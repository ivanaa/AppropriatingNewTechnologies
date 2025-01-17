#include "ofApp.h"

int width;
int height;

void ofApp::setup() {
    
    
camera.autosavePosition = true;
camera.loadCameraPosition();
    
    
    ofEnableAlphaBlending();
    
    
	ofSetVerticalSync(true);
    
	
    
	shader.load("DOFCloud");	
	focusDistance = 500;
	aperture = .2;
    
	//ofEnableAlphaBlending();
    
    mesh1.setup();
    //mesh2.setup();
    mesh3.setup();
}

void ofApp::update() {
    mesh1.update("beutiest sleep/", 161);
    mesh2.update("explosion", 161);
    mesh3.update("pretty sleep/", 161);
    
    
}

void ofApp::draw() {
	ofBackground(0);
	camera.begin();
	ofScale(1, -1, 1); // make y point down
    shader.begin();
	shader.setUniform1f("focusDistance", focusDistance);
    shader.setUniform1f("aperture", aperture);
	glEnable(GL_POINT_SMOOTH); // makes circular points
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);	// allows per-point size
    
    ofPushMatrix();
    ofTranslate(-400, 0,-300);
    ofRotateX(270);
    mesh2.draw();
    ofPopMatrix();
    //	ofBackground(0);
    
    
    ofPushMatrix();
    ofTranslate(-30,0, -300);
    mesh1.draw();
    ofPopMatrix();
    
    
    // ofPushMatrix();
    ofTranslate(-50, 0,-50);
    mesh3.draw();
    //ofPopMatrix();
 	ofBackground(0);
    
    shader.end(); 
    
    
    
    
    camera.end();
	
	ofSetColor(255);
	
//	ofDrawBitmapString("camera controls: click and drag the mouse to look.\nw: forward, s: backwards\na: //strafe left\nd: strafe right\ne: dolly up\nc: dolly down", ofPoint(30, 30));
    
    
    
    //cam.setDrag(0.6);
    //cam.end();
}

void ofApp::keyPressed(int key) {
	focusDistance = mouseX;
	aperture = ofMap(mouseY*2, 0, ofGetHeight(), 0, 1, true);
}