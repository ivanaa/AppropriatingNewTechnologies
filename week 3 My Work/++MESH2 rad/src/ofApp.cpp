#include "ofApp.h"

int width;
int height;

void ofApp::setup() {
    
    
    
	ofSetVerticalSync(true);
		
	shader.load("DOFCloud");	
	focusDistance = 500;
	aperture = .2;

	ofEnableAlphaBlending();
    
    mesh1.setup();
  //  mesh2.setup();
}

void ofApp::update() {
    mesh1.update("fetus/", 161);
    
 

    

  //  mesh1.path("ME");
  //  mesh2.update();

}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
	shader.begin();
	shader.setUniform1f("focusDistance", focusDistance);
	shader.setUniform1f("aperture", aperture);
	glEnable(GL_POINT_SMOOTH); // makes circular points
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);	// allows per-point size
    
	mesh1.draw();
   // mesh2.draw();
    shader.end();    
	cam.end();
}

void ofApp::keyPressed(int key) {
	focusDistance = mouseX;
	aperture = ofMap(mouseY, 0, ofGetHeight(), 0, 1, true);
}