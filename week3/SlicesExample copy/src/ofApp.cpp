#include "ofApp.h"

// save http://i.imgur.com/ym71g.gif as data/body.gif




void ofApp::setup() {
	ofSetVerticalSync(true);
    
    
	ofVideoPlayer body;
	body.loadMovie("6.gif");
	int n = body.getTotalNumFrames();
	for(int i = 0; i < n; i++) {
		// load and save the current frame
		body.setFrame(i);
		slices.push_back(body.getPixelsRef());
		// process each slice so the brightness determines the alpha
		slices.back().setImageType(OF_IMAGE_COLOR_ALPHA); // RGB -> RGBA
		ofPixels& pix = slices.back().getPixelsRef();
		for(int y = 0; y < pix.getHeight(); y++) {
			for(int x = 0; x < pix.getWidth(); x++) {
				ofColor cur = pix.getColor(x, y);
				cur.a = cur.getBrightness();
				pix.setColor(x, y, cur);
			}
		}
		// update the ofImage (upload ofPixels to ofTexture)
		slices.back().update();
	}
    
    
    
    
    
    
    ofVideoPlayer yes;
	yes.loadMovie("8.gif");
	int k = yes.getTotalNumFrames();
	for(int i = 0; i < k; i++) {
		// load and save the current frame
		yes.setFrame(i);
		slices1.push_back(yes.getPixelsRef());
		// process each slice so the brightness determines the alpha
		slices1.back().setImageType(OF_IMAGE_COLOR_ALPHA); // RGB -> RGBA
		ofPixels& pix = slices1.back().getPixelsRef();
		for(int y = 0; y < pix.getHeight(); y++) {
			for(int x = 0; x < pix.getWidth(); x++) {
				ofColor cur = pix.getColor(x, y);
				cur.a = cur.getBrightness();
				pix.setColor(x, y, cur);
			}
		}
		// update the ofImage (upload ofPixels to ofTexture)
		slices1.back().update();
	}

    
    
    
    
    
    
    
	ofEnableAlphaBlending();
}  

void ofApp::update() {
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofSetColor(255, 64); // make everything more transparent
	float spacing = 5;
    
    
    
    
    
    
	ofTranslate(-slices[0].getWidth() / 2, -slices[0].getHeight() / 2, -spacing * slices.size() / 2); // center things
	for(int f = 0; f < slices.size(); f++) {
		ofPushMatrix();
        ofTranslate(0, 0, f * spacing);
		
		// jiggle things
		float noiseOffset = ofGetElapsedTimef() + f;
		float noiseScale = 10;
		ofTranslate(0, 0, ofSignedNoise(0, noiseOffset) * noiseScale);
		
		slices[f].draw(0, 0);

        ofPopMatrix();

        
        
        
        
        
        ofTranslate(-slices1[0].getWidth() / 2, -slices1[0].getHeight() / 2, -spacing * slices1.size() / 2); // center things
        for(int w = 0; w < slices1.size(); w++) {
            ofPushMatrix();
            
            ofTranslate(0, 0, w * spacing);
            
            // jiggle things
            float noiseOffset = ofGetElapsedTimef() + w;
            float noiseScale = 10;
            ofTranslate(0, 0, ofSignedNoise(0, noiseOffset) * noiseScale);
            
            slices1[w].draw(0, 0);
            
            ofPopMatrix();

            
            

            
        }
            
            
            
       
		
		// space the slices out evenly on the z axis
	
        
        
	}
	cam.end();
}
