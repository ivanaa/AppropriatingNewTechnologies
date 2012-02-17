#pragma once

#include "ofMain.h"
#include "ofxMRI.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
   
	
	ofEasyCam cam;
	ofxMRI body, melon;
    //vector<ofImage> slices, melonslices;
};
