#include "ofMeshP.h"

ofMeshP::ofMeshP() {
	mesh.setMode(OF_PRIMITIVE_POINTS);
    currentFrame = 1;
    previousFrame = 0;    
}


void ofMeshP::setup() {
	img.loadImage("3.png");
}

void ofMeshP::update() {
    
    ////////////////////////////////////////////////  //JUSTIN
    
    
    //if space bar is pressed, increment playback number
    
    if(ofGetKeyPressed('p')) {
        skip++;
    }
    if(ofGetKeyPressed('o') && skip >= 1) {
        skip--;
    }
    
    
    if(currentFrame < 161){
        currentFrame++;
        
        cout<<"PLAYING"<<endl;
    }else{
        currentFrame = 1;
    }
    
    ostringstream fileNameToSave;
    fileNameToSave << currentFrame << ".png";
    frameResult = fileNameToSave.str(); 
    img.loadImage(frameResult);
    
    

    
    
    mesh.clear();
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
    
    
    
    
    
    
    ////////////////////////////////////////////////  //JUSTIN
    
    
    
    
    
	
}

void ofMeshP::draw() {
	mesh.draw();
}
