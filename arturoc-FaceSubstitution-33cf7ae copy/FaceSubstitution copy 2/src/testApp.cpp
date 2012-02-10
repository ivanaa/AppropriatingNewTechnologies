#include "testApp.h"

extern "C" {
#include "macGlutfix.h"
}

using namespace ofxCv;

void testApp::setup() {
#ifdef TARGET_OSX
	//ofSetDataPathRoot("../data/");
#endif
    
    
    tex.allocate(300,300, GL_RGBA);

    
    
    
	ofSetVerticalSync(true);
	cloneReady = false;
	cam.initGrabber(640, 480);
	clone.setup(cam.getWidth(), cam.getHeight());
	ofFbo::Settings settings;
	settings.width = cam.getWidth();
	settings.height = cam.getHeight();
	maskFbo.allocate(settings);
	srcFbo.allocate(settings);
	camTracker.setup();
	srcTracker.setup();
	srcTracker.setIterations(25);
	srcTracker.setAttempts(4);

	faces.allowExt("jpg");
	faces.allowExt("png");
	faces.listDir("faces");
	currentFace = 0;
	if(faces.size()!=0){
		loadFace(faces.getPath(currentFace));
    
	}
}

void testApp::update() {
    
    
   int w = 300;
	int h = 300;
	
	unsigned char * data = pixelsBelowWindow(ofGetWindowPositionX(),ofGetWindowPositionY(),w,h);
	
	// now, let's get the R and B data swapped, so that it's all OK:
	for (int i = 0; i < 300*300; i++){
		
            
            
            unsigned char r = data[i*4]; // mem A  
            
            
            data[i*4]   = data[i*4+1];   
            
            data[i*4+1] = data[i*4+2];   
            
            data[i*4+2] = data[i*4+3];   
            
            data[i*4+3] = r; 
	}
	
	
	if (data!= NULL) tex.loadData(data, 300, 300, GL_RGBA);
    
  
    if (data!= NULL) tex.loadData(data, 300, 300, GL_RGBA);

 //   if (data!= NULL) tex.loadData(data, 300, 300, GL_RGBA);

	cam.update();
	if(cam.isFrameNew()) {
		camTracker.update(toCv(cam));
		
		cloneReady = camTracker.getFound();
		if(cloneReady) {
			ofMesh camMesh = camTracker.getImageMesh();
			camMesh.clearTexCoords();
			camMesh.addTexCoords(srcPoints);
			
			maskFbo.begin();
			ofClear(0, 255);
			camMesh.draw();
			maskFbo.end();
			
			srcFbo.begin();
			ofClear(0, 255);
			src.bind();
			camMesh.draw();
			src.unbind();
			srcFbo.end();
			
			clone.setStrength(16);
			clone.update(srcFbo.getTextureReference(), cam.getTextureReference(), maskFbo.getTextureReference());
		}
	}
}

void testApp::draw() {
    
    
    
    
    
	ofSetColor(255);
	
	if(src.getWidth() > 0 && cloneReady) {
		clone.draw(0, 0);
        tex.draw(640,0, 300, 300);
        

	} else {
		cam.draw(0, 0);
        tex.draw(640,0, 300, 300);
        

	}
	
	if(!camTracker.getFound()) {
		drawHighlightString("camera face not found", 10, 10);
	}
	if(src.getWidth() == 0) {
		drawHighlightString("drag an image here", 10, 30);
	} else if(!srcTracker.getFound()) {
		drawHighlightString("image face not found", 10, 30);
	}
}

void testApp::loadFace(string face){
	src.setFromPixels(data, 300,300, OF_IMAGE_COLOR);
	if(src.getWidth() > 0) {
		srcTracker.update(toCv(src));
		srcPoints = srcTracker.getImagePoints();
        
	}
}

void testApp::dragEvent(ofDragInfo dragInfo) {
	//loadFace(dragInfo.files[0]);
}



/*void testApp::texFace(string face) {

	src.loadImage(face);
	if(src.getWidth() > 0) {
		srcTracker.update(toCv(src));
		srcPoints = srcTracker.getImagePoints();
        
	}






}
*/
void testApp::keyPressed(int RETURN){
	//switch(key){
	/*case OF_KEY_UP:
            
            src.loadImage(face);
            if(src.getWidth() > 0) {
                srcTracker.update(toCv(src));
                srcPoints = srcTracker.getImagePoints();
            }		
            break;
            */
            
   
            
            loadFace(face);


	

//	currentFace = ofClamp(currentFace,0,faces.size());
//	if(faces.size()!=0){
//		loadFace(faces.getPath(currentFace));
//	}
}
