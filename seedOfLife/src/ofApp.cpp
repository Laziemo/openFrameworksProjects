#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    ofSetFrameRate(1);
    ofEnableSmoothing();
    
    ofBackground(36);
    ofSetCircleResolution(200);
    
    title.load("Xenotron.ttf", 35);
    
    
   
    
    nucleus.setup();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update()

{
 
    for(int i=0; i<6; i++)
    {
        
        embryo[i].nX=nucleus.oX + ( cos ( (i*(PI/3)) ) * nucleus.R );
        embryo[i].nY=nucleus.oY + ( sin ( (i*(PI/3)) ) * nucleus.R );
        
    }

    //   Setting mid-Points nX,nY
    
    
    
}

//--------------------------------------------------------------

void ofApp::draw()
{
    
    ofPushMatrix();
    ofSetColor(255,255,255);
    title.drawString("Seed of Life", ofGetWidth()*0.22, 50);
    ofPopMatrix();
    
    
    
    nucleus.draw();
    
    ofSetLineWidth(4);
    for(int i=0; i<6; i++)
    {
        
        embryo[i].draw(embryo[i].nX, embryo[i].nY, nucleus.R);
        
    }
    
    
   
    //    Drawing all the circles
    
}


//--------------------------------------------------------------

