#include "testApp.h"
int w = 400;
int h = 300;


extern "C" {
#include "macGlutfix.h"
}



//--------------------------------------------------------------
void testApp::setup(){

    
    ofBackground(0, 0, 0 );
//	CGContextRef cgctx = NULL;
//	ofSetVerticalSync(true);
//    vidGrabber.setVerbose(true);
//    vidGrabber.initGrabber(w,h);
//    colorImg.allocate(w,h);
   
    head.loadImage("2.png");
    head.resize(200, 200);

    
    
	tex.allocate(w, h, GL_RGB);
	ofSetFrameRate(30);
    
    
//    colorImgOf.allocate(w,h,OF_IMAGE_COLOR_ALPHA);
    
    colorImg.allocate(w,h);
	grayImage.allocate(w,h);
	grayBg.allocate(w,h);
	grayDiff.allocate(w,h);
    
    
    
    colorFace.allocate(w,h,OF_IMAGE_COLOR);
    
	bLearnBakground = true;
	threshold = 80;

    haarFinder.setup("haarXML/haarcascade_frontalface_default.xml");

    
}




//--------------------------------------------------------------
void testApp::update(){
/*    
    bool bNewFrame = false;

    vidGrabber.grabFrame();
    bNewFrame = vidGrabber.isFrameNew();
	
	if (bNewFrame){
                colorImg.setFromPixels(vidGrabber.getPixels(), h,h);

    }
*/    

	
	unsigned char * data = pixelsBelowWindow(ofGetWindowPositionX(),ofGetWindowPositionY(),w,h);
	
    
    
    
	// now, let's get the R and B data swapped, so that it's all OK:
	for (int i = 0; i < w*h; i++){
		
		unsigned char r = data[i*4];
		data[i*4] = data[i*4+3];
		data[i*4+3] = r;
	}
    
        
    
    colorImgOf.setFromPixels(data, w, h, OF_IMAGE_COLOR_ALPHA);

    
/////////remove alpha:
    
    
    unsigned char * rgba = colorImgOf.getPixels();   
    
    //total rgb pixels  
    int totalPixels = w * h * 3;  
    
    int counter = 0;  //for stepping through the the rgba image  
    
    for(int i = 0; i < totalPixels; i+= 3){  
        data[i]    = rgba[counter];  
        data[i+1] = rgba[counter+1];  
        data[i+2] = rgba[counter+2];  
        
        counter+=4; //go to the next pixel for the rgba array  
    }  
    
    colorImg.setFromPixels(data, w, h);   

    
///////////    


    grayImage = colorImg; 

	
    //if (data!= NULL) tex.loadData(data, h, h, GL_RGBA);
	//cout << imageBelowWindow()[0] << endl;
        
    
    if (bLearnBakground == true){
        grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
        bLearnBakground = false;
    }

    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(80);
    
    // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    // also, find holes is set to true so we will get interior contours as well....
    contourFinder.findContours(grayDiff, 300, ((w*h)/3), 10, true);	// find holes
    
    
    haarFinder.findHaarObjects(grayImage, 0, 0, w, h);
    
	
	
//	glPushMatrix();
	
//	glTranslatef(20, 20, 0);
	
    

    
    
//	glPopMatrix();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0xffffff);

    grayImage.draw(0,0);

    
//	colorImgOf.draw(20,20)
//    ofFill();
	ofSetColor(255,0,0);

//    colorFace.draw(20,0);

	 //  ofNoFill();
	ofSetColor(0x333333);
    for (int i = 0; i < haarFinder.blobs.size(); i++){
        haarFinder.blobs[i].draw(0,0);
        ofRectangle cur = haarFinder.blobs[i].boundingRect;
        
        
        
        head.draw(cur.x,cur.y);
       
    }

    
    
    
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

