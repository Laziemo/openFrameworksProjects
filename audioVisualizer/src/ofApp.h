#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp
{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void playPressed();
    void stopPressed();
    
    
    ofSoundPlayer track;
    
    ofxPanel gui;
    
    
    ofxButton play;
    ofxButton stop;
    
    ofxFloatSlider volume;
    ofxFloatSlider rate;
    ofxFloatSlider center;
    ofxFloatSlider spread;
    
    ofxIntSlider bandRisk;
    ofxIntSlider red;
    ofxIntSlider green;
    ofxIntSlider blue;
    
    ofTrueTypeFont title;
    
    ofParameter <float> rotateX;
    ofParameter <float> rotateY;
    ofParameter <float> rotateZ;
    
    
    
    double *fftSmooth;
    double fftScaled;
    int fftColorMod;
    int bands;
    
    
    
    float rotationX;
    float rotationY;
    float rotationZ;
    
    
};
