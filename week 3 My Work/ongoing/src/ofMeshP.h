#pragma once

#include "ofMain.h"

class ofMeshP {
public:
    ofMeshP();
    
	void setup();
	void update(string hill, int max);
	void draw();
	
	ofVboMesh mesh;
    
    ofImage img; 
    ofImage img1;
    int width;
    int height; 
    int currentFrame;
    int previousFrame;
    string frameResult;
    string path;
    int skip;
    int l, now;
    
};
