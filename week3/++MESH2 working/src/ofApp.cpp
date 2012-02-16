#include "ofApp.h"




//JUSTIN
int currentFrame = 1;
int previousFrame = 0;
string frameResult;
int skip;	
int width;
int height;
//JUSTIN





void ofApp::setup() {
    
    
   // ofSetFrameRate(5);
	ofSetVerticalSync(true);
		
	shader.load("DOFCloud");	
	focusDistance = 500;
	aperture = .2;

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
    
    
   // if(ofGetKeyPressed(' ')) {
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
        



        
  /*      for(int y = 0; y < height - skip; y += skip) {
            // we need to skip so that the wireframe actually shows something
            
            for(int x = 0; x < width - skip; x += skip) {
                
                // this is kind of like quadrants
                
                ofVec3f nw = getVertexFromImg(img, x, y);
                ofVec3f ne = getVertexFromImg(img, x + skip, y);
                ofVec3f sw = getVertexFromImg(img, x, y + skip);
                ofVec3f se = getVertexFromImg(img, x + skip, y + skip);
                if(nw != 0 && ne != 0 && sw != 0 && se != 0) {  //this line checks for bad data
                    addFace(mesh, nw, ne, se, sw); //so long as nothing is zero.... otherwise vertices point to front of screen
                    
                }
            }
        }
        */
    
    
    ////////////////////////////////////////////////  //JUSTIN
    

    
    
    
	
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(1, -1, 1); // make y point down
	shader.begin();
	shader.setUniform1f("focusDistance", focusDistance);
	shader.setUniform1f("aperture", aperture);
	glEnable(GL_POINT_SMOOTH); // makes circular points
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);	// allows per-point size
	mesh.draw();
	shader.end();
    mesh.clear();

	cam.end();
}

void ofApp::keyPressed(int key) {
	focusDistance = mouseX;
	aperture = ofMap(mouseY, 0, ofGetHeight(), 0, 1, true);
}