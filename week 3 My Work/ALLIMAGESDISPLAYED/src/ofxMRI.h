#pragma once

#include "ofMain.h"

class ofxMRI  {
public:
	void setup(string filename);
	void update();
    void draw();
	//void draw(float x = 0, float y = 0, float z = 0);
    

	//ofEasyCam cam;
	vector<ofImage> slices;
    //vector<ofImage>melonslices;
};
