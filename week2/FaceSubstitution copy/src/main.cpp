#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1000, 800, OF_WINDOW);
	ofRunApp(new testApp());
}
