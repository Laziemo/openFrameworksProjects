#pragma once

#include "ofMain.h"
#include "ofxGui.h"



class zygote
{
    
public:
    
    int oX, oY, R;
    
    void setup()
    {
        
        
        oX=ofGetWidth()*0.5;
        oY=ofGetHeight()*0.5;
        R=36;
        
    }
    
    void draw()
    {
        ofSetColor(255,20);
        ofFill();
        ofSetLineWidth(1);
        ofDrawCircle(oX,oY,R);
        
        
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(2);
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
        
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(136,60);
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
    
    int p, jump, q, start, fly;
    
    int layer, max;
    
    float r,orX,orY;
    
    
    zygote nucleus;
    
    seedLing embryo[6];
    
    seedLing globule[1000000];
    
    ofTrueTypeFont title;
    
    
};
