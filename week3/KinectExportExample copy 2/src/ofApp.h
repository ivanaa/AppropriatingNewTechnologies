#pragma once


//#include "ofAddons.h"

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxControlPanel.h"



class ofApp : public ofBaseApp {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
    void eventsIn(guiCallbackData & data);

	
	ofxKinect kinect;
    ofxControlPanel gui;

    
    void setupControlPanel();

    
    ofTrueTypeFont TTF;

};
