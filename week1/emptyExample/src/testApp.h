#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCvHaarFinder.h"


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofVideoGrabber 		vidGrabber;
    
    ofxCvColorImage colorImg;
    ofImage			colorImgOf;

    ofImage			colorFace;


    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage 	grayBg;
    ofxCvGrayscaleImage 	grayDiff;
    
    ofxCvContourFinder 	contourFinder;
    ofxCvHaarFinder			haarFinder,x,y;

    
    int 				threshold;
    bool				bLearnBakground;

    ofImage         head;
    
	ofTexture	tex;
};

#endif
