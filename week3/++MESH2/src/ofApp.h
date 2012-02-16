#pragma once

#include "ofMain.h"
#include "ofMeshP.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofEasyCam cam;
    ofMeshP mesh1;
	ofShader shader;
	float focusDistance, aperture;
};
