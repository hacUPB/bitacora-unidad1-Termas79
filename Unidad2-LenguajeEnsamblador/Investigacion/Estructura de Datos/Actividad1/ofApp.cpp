#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
		backgroundHue = 0;
    // Inicializa la serpiente con varios nodos en el centro
    for (int i = 0; i < 20; i++) {
		    snake.emplace_back(ofGetWidth() / 2, ofGetHeight() / 2);
		    }
		}
//--------------------------------------------------------------
void ofApp::update() {
    glm::vec2 target = glm::vec2(ofGetMouseX(), ofGetMouseY());
    float interpolationFactor = 0.2;
    // controla la velocidad de movimiento (0-1)
    for (auto& pos : snake) {
		    pos = glm::mix(glm::vec3(pos, 0.0f), glm::vec3(target, 0.0f), 0.2);
		    // Se mueve gradualmente
		    target = pos;
		    // Cada nodo sigue al anterior
		    }
    backgroundHue = fmod(backgroundHue + 0.1, 255);
    }
//--------------------------------------------------------------
void ofApp::draw() {
		// Fondo dinámico con gradiente
		ofColor color1 = ofColor::fromHsb(backgroundHue, 150, 240);
		ofColor color2 = ofColor::fromHsb(fmod(backgroundHue + 128, 255), 150, 240);
		ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);

    // curva suave conectando los nodos
    if (snake.size() > 1) {
		    ofMesh mesh;
		    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
		    int index = 0;
		    for (const auto& pos : snake) {
				    float hue = ofMap(index++, 0, snake.size() - 1, 0, 255);
				    mesh.addColor(ofColor::fromHsb(hue, 200, 255));
				    mesh.addVertex(glm::vec3(pos, 0.0f));
				    }
				ofSetLineWidth(2);
				mesh.draw();
				}
    // Círculos con tamaño y color variable
    int index = 0;
    ofNoFill();
    ofSetLineWidth(2);
    for (const auto& pos : snake) {
		    float hue = ofMap(index, 0, snake.size() - 1, 0, 255);
		    ofSetColor(ofColor::fromHsb(hue, 220, 255));
		    float radius = ofMap(index++, 0, snake.size() - 1, 20, 5);
		    ofDrawCircle(pos.x, pos.y, radius);
		    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
		if (key == 'c') {
				snake.clear();
				}
		else if (key == 'a') {
				snake.emplace_back(ofRandomWidth(), ofRandomHeight());
				}
		else if (key == 'r') {
				if (!snake.empty()) {
						snake.pop_back();
						}
			  }
	  else if (key == 's') {
			  ofSaveFrame();
			  }
		}