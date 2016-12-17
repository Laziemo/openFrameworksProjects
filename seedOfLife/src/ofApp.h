#pragma once

#include "ofMain.h"



class zygote
{
    
public:
    
    int oX, oY, R;
    void setup()
    {
        
        
        oX=ofGetWidth()*0.5;
        oY=ofGetHeight()*0.5;
        R=148;
        
    }
    
    void draw()
    {
        ofSetColor(255,10);
        ofFill();
        ofSetLineWidth(1);
        ofDrawCircle(oX,oY,R);
        
        
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(6);
        ofDrawCircle(oX,oY,R);
    }
    
};

//=================================================

class seedLing: public zygote
{
    
public:
    
    
    float nX, nY;
    
    void setup()
    {
        
    }
    
    void draw(float nX, float nY, float R)
    {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), 92);
        ofNoFill();
        ofDrawCircle(nX,nY,R);
        
        ofSetColor(225,10);
        ofFill();
        ofDrawCircle(nX,nY,R);
    }
    
};

//=================================================


class ofApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();
    
    
    zygote nucleus;
    
    seedLing embryo[6];
    
    ofTrueTypeFont title;
    
    
    
};
