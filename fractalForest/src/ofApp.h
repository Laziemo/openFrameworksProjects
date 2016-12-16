#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class rain
{
    
public:
    
    float x=ofRandom(ofGetWidth());
    float y = ofRandom(-200,-100);
    float yspeed=ofRandom(200);
    
    void fall(){
        y+=yspeed;
        if (y>ofGetHeight())
        {
            y=ofRandom(-200,-100);
        }
    }
    
    void draw(float r, float alp){
        ofSetColor(138,43,226,50);
        ofDrawLine(x,y,x,y+10);
       
        ofSetColor(138,43,226,alp);
        ofFill();
        ofDrawSphere(ofRandom(ofGetWidth()),y,r);
      
    }
};

//=============================================================================================================


class ofApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();
    
    void branch(float,float);
    void addTree(float, int, float);
    
    float len, angle;
    
    float pos, spr, rad;
    int h;
    
    float val,val1,val2, r,g,b;
    
    
    
    double *fftSmooth;
    double fftScaled;
    int fftColorMod;
    int bands;
    float rate;
    
    
    float odd,oddB;
    float col;
    

    
    rain drop[800];
    
    ofSoundPlayer ambience;
    ofSoundPlayer cbl;
    
    ofTrueTypeFont title;
    
//    ofxPanel gui;
//    ofParameter<float> rate;
    
};
//=============================================================================================================



