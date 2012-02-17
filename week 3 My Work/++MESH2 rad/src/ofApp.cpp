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
    mesh2.setup();
    mesh3.setup();
}

void ofApp::update() {
    mesh1.update("fetus/", 161);
    mesh2.update("sp/", 161);
    mesh3.update("w9/", 161);


}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
//	shader.begin();
//	shader.setUniform1f("focusDistance", focusDistance);
//	shader.setUniform1f("aperture", aperture);
	glEnable(GL_POINT_SMOOTH); // makes circular points
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);	// allows per-point size
    
	mesh1.draw();
    
    
    ofPushMatrix();
    ofTranslate(-30, 30);
    mesh2.draw();
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(40, 40);
    ofRotateY(90);
    mesh3.draw();
    ofPopMatrix();
 
    
    
    
    //  shader.end(); 
    
    cam.end();
}

void ofApp::keyPressed(int key) {
	focusDistance = mouseX;
	aperture = ofMap(mouseY, 0, ofGetHeight(), 0, 1, true);
}