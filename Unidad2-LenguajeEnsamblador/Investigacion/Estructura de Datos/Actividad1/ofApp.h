#pragma once
#include "ofMain.h"
#include <list>
class ofApp : public ofBaseApp {
		public:
				std::list<glm::vec2> snake;
				float backgroundHue;
		    void setup();
		    void update();
		    void draw();
		    void keyPressed(int key);
		    };