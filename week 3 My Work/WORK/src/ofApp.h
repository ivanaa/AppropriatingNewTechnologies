#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxControlPanel.h"



class ofApp : public ofBaseApp {
public:
    
	void setup();
	void update();
	void draw();
	void exit();
    
	ofxKinect kinect;
    ofImage img;
    
    
    ofxControlPanel gui;
    
    
    //void setupControlPanel();
    
    
    ofTrueTypeFont TTF;

    
};