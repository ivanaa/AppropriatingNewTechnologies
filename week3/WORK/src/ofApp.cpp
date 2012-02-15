#include "ofApp.h"

#include <string>
#include <sstream>

//gives you an image in the rgb+alpha format in png

bool recordingOn = false;
int frameNumber = 0;
ostringstream Name;

void ofApp::setup() {
  
    
  //  setupControlPanel();
    
    
    ofxControlPanel::setBackgroundColor(simpleColor(30, 30, 60, 200));
	ofxControlPanel::setTextColor(simpleColor(240, 50, 50, 255));
    
    gui.loadFont("MONACO.TTF", 8);		
	gui.setup("test cv", 0, 0,50, 100);
	gui.addPanel("background subtraction example", 4, false);
	//gui.addButtonSlider("threshold", "BG_THRESHOLD", 29.0, 1.0, 255.0, false);	
    
    
	kinect.init(true, true, true); 
    kinect.setDepthClipping(100, 1700);
	kinect.setRegistration(true);
	kinect.open();

    
    
    //    ofImage_::ofImage(const ofPixels_< PixelType > &pix)
  img.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    
    
}

void ofApp::update() {
    
    kinect.update();
    if(ofGetKeyPressed('3')) {
        recordingOn =! recordingOn;
    }
    
    else {
    if (recordingOn==true && ofGetKeyPressed(' '))
        
        recordingOn =false;
    
    
    }
    
    
    
    
	if(kinect.isFrameNew()) { 
        if (recordingOn == true && frameNumber <= 200) {
			ofPixels& depthPixels = kinect.getDepthPixelsRef();
			ofPixels& colorPixels = kinect.getPixelsRef();
			for(int y = 0; y < 480; y++) {
				for(int x = 0; x < 640; x++) {
					ofColor color = colorPixels.getColor(x, y);
					ofColor depth = depthPixels.getColor(x, y);
					img.setColor(x, y, ofColor(color, depth.getBrightness()));
                    
				}
			}
            frameNumber = frameNumber + 1;
            ostringstream Name;
            Name << frameNumber << ".png";
            string result = Name.str();
			img.saveImage(result);
            cout<<"recording"<<endl;
		}
    }
}

void ofApp::draw() {
    
	ofBackground(0);
	ofSetColor(255, 255, 255);
	kinect.drawDepth(0, 0, 640, 480);
	kinect.draw(640, 0, 640, 480);
    gui.draw();

    
}

void ofApp::exit() {
	kinect.close();
}
