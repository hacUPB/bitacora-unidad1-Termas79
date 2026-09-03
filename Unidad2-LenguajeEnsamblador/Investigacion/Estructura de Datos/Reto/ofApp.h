#pragma once
#include "ofMain.h"

// Nodo de la cola
struct Node {
	float x, y;
	float radius;
	ofColor color;
	float opacity;
	Node* next;
	Node(float _x, float _y, float _radius, ofColor _color, 
		 float _opacity) : x(_x), y(_y), radius(_radius), 
		 color(_color), opacity(_opacity), next(nullptr) {}
};
// Implementación manual de una cola (FIFO)
class BrushQueue {
public:
	Node* front;
	Node* rear;
	int size;
	int maxSize;
	BrushQueue(int _maxSize);
	~BrushQueue();
	void enqueue(float x, float y, float radius, ofColor color, 
				 float opacity);
	void dequeue();
	void clear();
	bool isEmpty();
};

// Constructor
BrushQueue::BrushQueue(int _maxSize) : front(nullptr), rear(nullptr), 
size(0), maxSize(_maxSize) {}
// Destructor
BrushQueue::~BrushQueue() {
	clear();
}
// Implementa aquí `enqueue()`
void BrushQueue::enqueue(float x, float y, float radius, ofColor color, 
	float opacity) {
	// TODO: crear un nuevo nodo y agregarlo al final de la cola.
	// Si la cola supera `maxSize`, eliminar el nodo más antiguo con `dequeue()`.
	Node* newNode = new Node(x, y, radius, color, opacity);
    if (front == nullptr) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	size++;
	if (size > maxSize) {
		dequeue();
	}
}	
// Implementa aquí `dequeue()`
void BrushQueue::dequeue() {
	// TODO: eliminar el nodo más antiguo si la cola no está vacía.
	if (front != nullptr) {
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
		if (front == nullptr) {
			rear = nullptr;
		}
	}
}
// Implementa aquí `clear()`
void BrushQueue::clear() {
	// TODO: eliminar todos los nodos de la cola.
	while (!isEmpty()) {
		dequeue();
	}
}
// Implementa aquí `isEmpty()`
bool BrushQueue::isEmpty() {
	// TODO: retornar si la cola está vacía.
	return size == 0;
}

class ofApp : public ofBaseApp {
public:
	BrushQueue strokes; // Cola de trazos
	float backgroundHue = 0;
    int lastMouseX = 0;
	int lastMouseY = 0;
    int previousMouseX = 0;
	int previousMouseY = 0;
	ofApp() : strokes(50) {} // Tamaño máximo de la cola
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    void mouseMoved(int x, int y);
	void mousePressed(int x, int y, int button);

	int getMouseX() const {
		return ofGetMouseX();
	}

	int getMouseY() const {
		return ofGetMouseY();
	}
};