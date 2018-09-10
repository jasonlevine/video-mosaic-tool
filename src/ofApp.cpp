#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(320, 240);
    grabber.initGrabber(320, 240);
    ofSetFrameRate(30);
    loops.push_back(vector<ofFbo>());
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    ofFbo fbo;
    fbo.allocate(320, 240);
    fbo.begin();
    grabber.draw(0,0);
    fbo.end();
    
    loops.back().push_back(fbo);
    if (loops.back().size() > 300) loops.back().erase(loops.back().begin());
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    int rows;
    int cols;
    
    if (loops.size() == 1) {
        rows = cols = 1;
    }
    else if (loops.size() == 2){
        rows = 1;
        cols = 2;
    }
    else if (loops.size() <= 4){
        rows = 2;
        cols = 2;
    }
    else if (loops.size() <= 6){
        rows = 2;
        cols = 3;
    }
    else if (loops.size() <= 9){
        rows = 3;
        cols = 3;
    }
    else if (loops.size() <= 16){
        rows = 4;
        cols = 4;
    }
    
    float w = ofGetWidth() / cols;
    float h = ofGetHeight() / rows;
    
    for (int i = 0; i < loops.size(); i++) {
        int frame = (i == loops.size()-1) ? loops[i].size()-1 : ofGetFrameNum() % loops[i].size();
        int x = i % cols * w;
        int y = i / cols * h;
        loops[i][frame].draw(x, y, w, h);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        loops.push_back(vector<ofFbo>());
        if (loops.size() > 16) loops.erase(loops.begin());
    }
    
    if (key == OF_KEY_BACKSPACE){
        loops.erase(loops.begin() + loops.size()-2);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
