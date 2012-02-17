#pragma once

#include "ofMain.h"
#include "ofMeshP.h"
#include "ofxMRI.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofEasyCam cam;
    ofMeshP mesh1;
    ofMeshP mesh2;
    ofMeshP mesh3;
	ofShader shader;
	float focusDistance, aperture;
	//ofEasyCam cam;
	ofxMRI body, melon;


};
