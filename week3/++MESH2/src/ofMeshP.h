#pragma once

#include "ofMain.h"

class ofMeshP {
public:
    ofMeshP();
    
	void setup();
	void update();
	void draw();
	
	ofMesh mesh;
    
    ofImage img;   
    int width;
    int height; 
    int currentFrame;
    int previousFrame;
    string frameResult;
    int skip;

};
