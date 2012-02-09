#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
	cam.initGrabber(640, 480);
	
	tracker.setup();
    srcTracker.setup();
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
        srcTracker.update(toCv(cam));
        
        
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
        
        
        
		srcPoints = srcTracker.getImagePoints();
	}
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	
	if(tracker.getFound()) {
		ofSetLineWidth(0);
		//tracker.draw();
    
       // ofMesh objectMesh = tracker.getObjectMesh();
ofMesh meanMesh = tracker.getMeanObjectMesh();
        meanMesh.clearTexCoords();
        meanMesh.addTexCoords(srcPoints);

        
        
		//easyCam.begin();
		ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
	    ofTranslate(position);
		applyMatrix(rotationMatrix);
		ofScale(scale,scale,scale);
		//ofDrawAxis(scale);
        
        
        cam.getTextureReference().bind();
        //camMesh.draw();
        meanMesh.draw();
        cam.getTextureReference().unbind();

		//tracker.getObjectMesh().drawWireframe();
		//easyCam.end();
	}
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}