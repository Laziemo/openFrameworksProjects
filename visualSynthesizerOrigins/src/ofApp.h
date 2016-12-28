#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased();
    
    
    void stripePattern();
    void matrixPattern();
    
    ofxPanel gui;
    
    ofxGuiGroup dimension;
    ofxGuiGroup character;
    ofxGuiGroup primitive;
    ofxGuiGroup global;
    
    ofxVec2Slider size;
    ofxToggle fill, type;
    
    ofParameter<float> scaleG;
    ofParameter<float> rotG;
    
    ofParameter<int> countX;
    ofParameter<float> tran;
    ofParameter<int> rotX;
    
    ofParameter<bool> random;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    ofParameter<int> alpha;
    
    ofParameter<int> width;
    ofParameter<float> scale;
    ofParameter<float> shiftY;
    ofParameter<float> rotL;
    
    ofParameter<int> countY;
    ofParameter<float> stepY;
    ofParameter<float> rotY;
    ofParameter<float> pinchY;
    
    
    
    bool showGui;
    
    
};
