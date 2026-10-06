#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
}
//--------------------------------------------------------------
void ofApp::update() {
	backgroundHue += 0.2;
	if (backgroundHue > 255) {
		backgroundHue = 0;
	}

    if (strokes.front != nullptr) {
		float targetX = ofGetMouseX();
		float targetY = ofGetMouseY();
		const float interpolationFactor = 0.2f;
		Node* current = strokes.front;

		while (current != nullptr) {
			current->x = ofLerp(current->x, targetX, interpolationFactor);
			current->y = ofLerp(current->y, targetY, interpolationFactor);
			targetX = current->x;
			targetY = current->y;
			current = current->next;
		}
	}
}
//--------------------------------------------------------------
void ofApp::draw() {
	ofColor color1, color2;
	color1.setHsb(backgroundHue, 150, 240);
	color2.setHsb(fmod(backgroundHue + 128, 255), 150, 240);
	ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);

	auto* current = strokes.front;

	while (current != nullptr) {
		ofColor strokeColor = current->color;
		strokeColor.a = static_cast<unsigned char>(current->opacity);

		ofSetColor(strokeColor);
		ofDrawCircle(current->x, current->y, current->radius);

		current = current->next;
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'c') {
		strokes.clear();
	}
	else if (key == 'a') {
		strokes.maxSize = strokes.maxSize == 50 ? 100 : 50;

		while (strokes.size > strokes.maxSize) {
			strokes.dequeue();
		}

		if (strokes.rear != nullptr) {
			while (strokes.size < strokes.maxSize) {
				float radius = ofRandom(5, 20);
				ofColor color;
				color.setHsb(ofRandom(255), 200, 255);
				float opacity = ofRandom(100, 255);

				strokes.enqueue(
					strokes.rear->x,
					strokes.rear->y,
					radius,
					color,
					opacity);
			}
		}
	}
	else if (key == 's') {
		ofSaveFrame();
	}
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	previousMouseX = lastMouseX;
	previousMouseY = lastMouseY;
	lastMouseX = x;
	lastMouseY = y;
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
   if (button == OF_MOUSE_BUTTON_LEFT) {
		while (strokes.size < strokes.maxSize) {
			float radius = ofRandom(5, 20);
			ofColor color;
			color.setHsb(ofRandom(255), 200, 255);
			float opacity = ofRandom(100, 255);
			strokes.enqueue(x, y, radius, color, opacity);
		}
	}
}