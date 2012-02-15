#include "ofApp.h"

void ofApp::setup() {
    
    setupControlPanel();
    
    
    ofxControlPanel::setBackgroundColor(simpleColor(30, 30, 60, 200));
	ofxControlPanel::setTextColor(simpleColor(240, 50, 50, 255));

    gui.loadFont("MONACO.TTF", 8);		
	gui.setup("test cv", 0, 0,50, 100);
	gui.addPanel("background subtraction example", 4, false);
	//gui.addButtonSlider("threshold", "BG_THRESHOLD", 29.0, 1.0, 255.0, false);	
    
    
	kinect.init(true, true, true);
    kinect.setDepthClipping(100, 1500);
	kinect.setRegistration(true);
	kinect.open();
}

void ofApp::update() {
	kinect.update();
	if(kinect.isFrameNew()) {
		if(ofGetKeyPressed(' ')) {
			ofPixels& depthPixels = kinect.getDepthPixelsRef();
			ofPixels& colorPixels = kinect.getPixelsRef();
			ofImage img;
			img.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
			for(int y = 0; y < 480; y++) {
				for(int x = 0; x < 640; x++) {
					ofColor color = colorPixels.getColor(x, y);
					ofColor depth = depthPixels.getColor(x, y);
					img.setColor(x, y, ofColor(color, depth.getBrightness()));
				}
			}
			img.saveImage("out.png");
		}
	}
}

void ofApp::draw() {
	ofBackground(0);
    
    //cout << gui.getValueI("MY_VAR");
    
    
  //  kinect.
	ofSetColor(255, 255, 255);
	kinect.drawDepth(0, 0, 640, 480);
	kinect.draw(0, 480, 640, 480);
    
    ofSetHexColor(0xffffff);
	gui.draw();

}

void ofApp::exit() {
	kinect.close();
}

//=========================================================================
void ofApp::setupControlPanel(){
	//gui.setup("EyeShine", 20, 70, 300, 500);
    
    //gui.addSlider("slider var", "MY_VAR", 29.0, 1.0, 255.0, false);	
	
	//gui.addPanel(" Capture Controls", 1);
	//gui.addSlider("setDepthClipping", "ADAPTHRESH_BLOCKSIZE", 10, 1, 25, true);	

	//gui.loadSettings("settings/controlPanelSettings.xml");
}

