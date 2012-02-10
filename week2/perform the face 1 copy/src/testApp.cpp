#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
    
#ifdef TARGET_OSX
	ofSetDataPathRoot("../data/");
#endif
    
    
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
	cam.initGrabber(640, 480);
	
	tracker.setup();
    srcTracker.setup();
    
    bitesFbo.allocate(640,480, GL_RGBA);
    
    
    faces.allowExt("jpg");
	faces.allowExt("png");
	faces.listDir("faces");
	currentFace = 0;
	if(faces.size()!=0){
		loadFace(faces.getPath(currentFace));

        
    }      
        
}

void testApp::update()
    {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
        srcTracker.update(toCv(cam));
        
        
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
        
        srcPoints = srcTracker.getImagePoints();
        
        ofDirectory faces;
        int currentFace;
	}
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	
	if(tracker.getFound()) {
		ofSetLineWidth(0);
		//tracker.draw();
        
        
        ofPolyline mouthLine = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH);
        
       bitesFbo.begin();
        //ofClear(255,0);

       ofPushStyle();
        ofSetColor(0);
        ofFill();
        mouthLine.draw();
        ofPopStyle();
        bitesFbo.end();
        
        
    
       // ofMesh objectMesh = tracker.getObjectMesh();
ofMesh meanMesh = tracker.getMeanObjectMesh();
        meanMesh.clearTexCoords();
        meanMesh.addTexCoords(srcPoints);

        
       ofPushMatrix();
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
       ofPopMatrix();
        
       bitesFbo.draw(0,0);
		//tracker.getObjectMesh().drawWireframe();
		//easyCam.end();
	}
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}