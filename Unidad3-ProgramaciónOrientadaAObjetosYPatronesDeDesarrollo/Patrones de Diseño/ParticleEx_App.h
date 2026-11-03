#pragma once
#include "ofMain.h"
#include <string>
#include <vector>

class Observer {
public:
	virtual ~Observer() = default;
	virtual void onNotify(const std::string& event) = 0;
};

class Subject {
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
protected:
	void notify(const std::string& event);
private:
	std::vector<Observer*> observers;
};

class Particle;

class State {
public:
	virtual ~State() = default;
	virtual void update(Particle* particle) = 0;
	virtual void onEnter(Particle* particle) {}
	virtual void onExit(Particle* particle) {}
};

class Particle : public Observer {
public:
	Particle();
	~Particle() override;
	Particle(const Particle&) = delete;
	Particle& operator=(const Particle&) = delete;
	void update();
	void draw();
	void onNotify(const std::string& event) override;
	void setState(State* newState);
	ofVec2f position;
	ofVec2f velocity;
	float size;
	ofColor color;
private:
	void keepInsideWindow();
	State* state;
};

class NormalState : public State {
public:
	void update(Particle* particle) override;
	void onEnter(Particle* particle) override;
};

class AttractState : public State {
public:
	void update(Particle* particle) override;
};

class RepelState : public State {
public:
	void update(Particle* particle) override;
};

class StopState : public State {
public:
	void update(Particle* particle) override;
};
class ParticleFactory {
public:
	static Particle* createParticle(const std::string& type);
};
class ofApp : public ofBaseApp, public Subject {
public:
	~ofApp() override;
	void setup() override;
	void update() override;
	void draw() override;
	void keyPressed(int key) override;
private:
	std::vector<Particle*> particles;
};