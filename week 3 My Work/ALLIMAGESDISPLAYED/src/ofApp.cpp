#include "ofApp.h"

// save http://i.imgur.com/ym71g.gif as data/body.gif

//Coding advice: make fewer decisions so you can make fewer mistakes

void ofApp::setup() {
	ofSetVerticalSync(true);
    body.setup("body.gif");
    melon.setup("melon.gif");
	ofEnableAlphaBlending();
}  
  

void ofApp::update() {
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofSetColor(255, 64); // make everything more transparent
    
  //  body.draw(0,0,0);
    body.draw();
    ofPushMatrix();
   // ofTranslate();
    melon.draw();
	ofPopMatrix();
    
    cam.end();
}
