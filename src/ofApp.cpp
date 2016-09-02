#include "ofApp.h"

int w = 256;
int h = 256;
ofImage image;	 	//Declare image object

//--------------------------------------------------------------
void ofApp::setup(){
    //Set window size
    ofSetWindowShape(w, h);
    
	//Create image w x h pixels
	image.allocate(w, h, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	//Set image pixels
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			//Compute preliminary values,
			//needed for our pixel color calculation:

			//1. Time from application start
			float time = ofGetElapsedTimef();

			//2. Level of hyperbola value of x and y with
			//center in w/2, h/2
			float v = (x-w/2) * (y-h/2);

			//3. Combining v with time for motion effect
			float u= v * 0.00025 + time;

			//4. Compute color components as periodical 
			//functions of u, and stretched to [0..255]
			int red = ofMap(sin( u ), -1, 1, 0, 255);
			int green = ofMap(sin( u * 2 ), -1, 1, 0, 255);
			int blue = 255-green;
        
            //5. Set pixel's color
            ofColor color(red, green, blue);
            image.setColor(x, y, color);
        }
	}
    //Notify openFrameworks that image's pixels were changed,
    //it will update image's texture for drawing
    image.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);	//Set up white background
	ofSetColor(255);	//Set color for image drawing
	image.draw(0, 0);				//Draw image
    
    ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

} 

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}