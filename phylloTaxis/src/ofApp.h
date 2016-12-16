#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    float theta, r, x, y;
    int n;
    
    ofxPanel gui;
    
    ofParameter<float> ang;
    ofParameter<float> spread;
    ofParameter<float> radius;
    ofParameter<bool> reset;
    ofParameter<bool> filler;
    ofParameter<float> alpha;

    
    
};
