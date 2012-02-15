#include "ofApp.h"






	
int width;
int height;






void ofApp::setup() {
    
       
    
    mesh1.setup();
    
	ofSetVerticalSync(true);
		
	shader.load("DOFCloud");	
	focusDistance = 500;
	aperture = .2;

	ofEnableAlphaBlending();
}

void ofApp::update() {
    
    ////////////////////////////////////////////////  //JUSTIN
    
    
    //if space bar is pressed, increment playback number
    
         
        
        
        
        
    



    
    
    ////////////////////////////////////////////////  //JUSTIN
    

    
    
    
	
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
	//shader.begin();
	//shader.setUniform1f("focusDistance", focusDistance);
	//shader.setUniform1f("aperture", aperture);
	glEnable(GL_POINT_SMOOTH); // makes circular points
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);	// allows per-point size
	mesh1.draw();
	//shader.end();
   
	cam.end();
}

void ofApp::keyPressed(int key) {
	focusDistance = mouseX;
	aperture = ofMap(mouseY, 0, ofGetHeight(), 0, 1, true);
}