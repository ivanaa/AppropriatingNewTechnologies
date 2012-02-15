#include "ofMeshP.h"




//JUSTIN
int currentFrame = 1;
int previousFrame = 0;
string frameResult;
int skip;	
int width;
int height;
//JUSTIN





void ofApp::setup() {
	ofSetVerticalSync(true);
		

	ofImage img;
	img.loadImage("3.png");
	mesh.setMode(OF_PRIMITIVE_POINTS);
	ofEnableAlphaBlending();
}

void ofApp::update() {
    
    ////////////////////////////////////////////////  //JUSTIN
    
    
    //if space bar is pressed, increment playback number
    
    if(ofGetKeyPressed('p')) {
        skip++;
    }
    if(ofGetKeyPressed('o') && skip >= 1) {
        skip--;
    }
    
    
    if(ofGetKeyPressed(' ')) {
        if(currentFrame < 201){
            currentFrame++;
            
            cout<<"PLAYING"<<endl;
        }else{
            currentFrame = 1;
        }
        
        ostringstream fileNameToSave;
        fileNameToSave << currentFrame << ".png";
        frameResult = fileNameToSave.str(); 
        img.loadImage(frameResult);
       	
        
        
        
        
        
        
        
        for(int y = 0; y < img.getHeight(); y++) {
            for(int x = 0; x < img.getWidth(); x++) {
                ofColor cur = img.getColor(x, y);
                if(cur.a > 0) {
                    // the alpha value encodes depth, let's remap it to a good depth range
                    float z = ofMap(cur.a, 0, 255, -480, 480);
                    cur.a = 255;
                    mesh.addColor(cur);
                    ofVec3f pos(x - img.getWidth() / 2, y - img.getHeight() / 2, z);
                    mesh.addVertex(pos);
                    
                }
            }
        }
        



    }
    
    ////////////////////////////////////////////////  //JUSTIN
    

    
    
    
	
}

void ofApp::draw() {
	ofBackground(0);
//	cam.begin();
	ofScale(1, -1, 1); // make y point down
	mesh.draw();
    mesh.clear();

	//cam.end();
}

void ofApp::keyPressed(int key) {

}