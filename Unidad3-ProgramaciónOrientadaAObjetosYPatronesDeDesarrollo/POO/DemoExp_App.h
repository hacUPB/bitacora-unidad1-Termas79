#pragma once
#include "ofMain.h"
#include <vector>
// -------------------------------------------------
// Clase base abstracta: Particle
// -------------------------------------------------
class Particle {
public:
	virtual ~Particle() {}
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	virtual bool isDead() const = 0;
	// Nuevo método para saber si la partícula (tipo RisingParticle) debe explotar
	virtual bool shouldExplode() const { return false; }
	// Métodos para obtener posición y color, para usarlos en explosiones
	virtual glm::vec2 getPosition() const { return glm::vec2(0, 0); }
	virtual ofColor getColor() const { return ofColor(255); }
};
// -------------------------------------------------
// RisingParticle: Partícula que nace en la parte inferior central y sube
// -------------------------------------------------
class RisingParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float lifetime;
	// tiempo máximo antes de explotar
	float age;
	bool exploded;
public:
	RisingParticle(const glm::vec2& pos, const glm::vec2& vel, const ofColor& col, float life)
		: position(pos), velocity(vel), color(col), lifetime(life), age(0), exploded(false) {
	}
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		// Aumenta la desaceleración para dar sensación de recorrido largo
		velocity.y += 9.8f * dt * 8;
		// Condición de explosión: cuando la partícula alcanza aproximadamente el 15% de la altura
		float explosionThreshold = ofGetHeight() * 0.15 + ofRandom(-30, 30);
		if (position.y <= explosionThreshold || age >= lifetime) {
			exploded = true;
		}
	}
	void draw() override {
		ofSetColor(color);
		// Partícula más grande
		ofDrawCircle(position, 10);
	}
	bool isDead() const override { return exploded; }
	bool shouldExplode() const override { return exploded; }
	glm::vec2 getPosition() const override { return position; }
	ofColor getColor() const override { return color; }
};

// -------------------------------------------------
//Particula Nueva #1 (FallingParticle): Partícula que cae desde la parte superior central y se mueve hacia abajo
// -------------------------------------------------
class FallingParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float lifetime;
	float age;
	bool exploded;
public:
	FallingParticle(const glm::vec2& pos, const glm::vec2& vel, const ofColor& col, float life)
		: position(pos), velocity(vel), color(col), lifetime(life), age(0), exploded(false) {
	}
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		// Aumenta la aceleración para dar sensación de caída rápida
		velocity.y -= 9.8f * dt * 8;
		float explosionThreshold = ofGetHeight() * 0.85 + ofRandom(-30, 30);
		if (position.y >= explosionThreshold || age >= lifetime) {
			exploded = true;
		}
	}
	void draw() override {
		ofSetColor(color);
		ofDrawCircle(position, 10);
	}
	bool isDead() const override { return exploded; }
	bool shouldExplode() const override { return exploded; }
	glm::vec2 getPosition() const override { return position; }
	ofColor getColor() const override { return color; }
};
// -------------------------------------------------
//Particula Nueva #2 (SideParticle): Partícula que se mueve desde los lados hacia el centro y explota al llegar al centro
class SideParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float lifetime;
	float age;
	bool exploded;
	int sizeX = (rand() % 2 + 3) * 10;
	int sizeY = (rand() % 2 + 3) * 10;
public:
	SideParticle(const glm::vec2& pos, const glm::vec2& vel, const ofColor& col, float life)
		: position(pos), velocity(vel), color(col), lifetime(life), age(0), exploded(false) {
	}
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		// Condición de explosión: cuando la partícula alcanza el centro horizontal de la pantalla
		float explosionThreshold = ofGetWidth() * 0.5 + ofRandom(-30, 30);
		if ((velocity.x > 0 && position.x >= explosionThreshold)
			|| (velocity.x < 0 && position.x <= explosionThreshold)
			|| age >= lifetime) {
			exploded = true;
		}
	}
	void draw() override {
		ofSetColor(color);
		ofDrawRectangle(position.x, position.y, sizeX, sizeY);
	}
	bool isDead() const override { return exploded; }
	bool shouldExplode() const override { return exploded; }
	glm::vec2 getPosition() const override { return position; }
	ofColor getColor() const override { return color; }
};
// -------------------------------------------------
// Clase base para explosiones: ExplosionParticle
// -------------------------------------------------
class ExplosionParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float age;
	float lifetime;
	float size;
	// tamaño de la partícula de explosión
public:
	ExplosionParticle(const glm::vec2& pos, const glm::vec2& vel, const ofColor& col, float life, float sz)
		: position(pos), velocity(vel), color(col), age(0), lifetime(life), size(sz) {
	}
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		float alpha = ofMap(age, 0, lifetime, 255, 0, true);
		color.a = alpha;
	}
	bool isDead() const override {
		return age >= lifetime;
	}
};
// -------------------------------------------------
// CircularExplosion: Explosión en patrón circular
// -------------------------------------------------
class CircularExplosion : public ExplosionParticle {
public:
	CircularExplosion(const glm::vec2& pos, const ofColor& col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.2f, ofRandom(16, 32)) {
		float angle = ofRandom(0, TWO_PI);
		float speed = ofRandom(80, 200);
		velocity = glm::vec2(cos(angle), sin(angle)) * speed;
	}
	void draw() override {
		ofSetColor(color);
		ofDrawCircle(position, size);
	}
};
// -------------------------------------------------
// RandomExplosion: Explosión con direcciones aleatorias
// -------------------------------------------------
class RandomExplosion : public ExplosionParticle {
public:
	RandomExplosion(const glm::vec2& pos, const ofColor& col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.5f, ofRandom(16, 32)) {
		velocity = glm::vec2(ofRandom(-200, 200), ofRandom(-200, 200));
	}
	void draw() override {
		ofSetColor(color);
		ofDrawRectangle(position.x, position.y, size, size);
	}
};
// -------------------------------------------------
// StarExplosion: Explosión en forma de estrella
// -------------------------------------------------
class StarExplosion : public ExplosionParticle {
public:
	StarExplosion(const glm::vec2& pos, const ofColor& col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.3f, ofRandom(20, 40)) {
		float angle = ofRandom(0, TWO_PI);
		float speed = ofRandom(90, 180);
		velocity = glm::vec2(cos(angle), sin(angle)) * speed;
	}
	void draw() override {
		ofSetColor(color);
		int rays = 5;
		float outerRadius = size;
		float innerRadius = size * 0.5;
		ofPushMatrix();
		ofTranslate(position);
		for (int i = 0; i < rays; i++) {
			float theta = ofMap(i, 0, rays, 0, TWO_PI);
			float xOuter = cos(theta) * outerRadius;
			float yOuter = sin(theta) * outerRadius;
			float xInner = cos(theta + PI / rays) * innerRadius;
			float yInner = sin(theta + PI / rays) * innerRadius;
			ofDrawLine(0, 0, xOuter, yOuter);
			ofDrawLine(xOuter, yOuter, xInner, yInner);
		}
		ofPopMatrix();
	}
};
// -------------------------------------------------
// ofApp: Manejo de la escena y eventos
// -------------------------------------------------
class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
	std::vector<Particle*> particles;
	~ofApp();
private:
	void createRisingParticle();
	void createFallingParticle();
	void createSideParticle();
};