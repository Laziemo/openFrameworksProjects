#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAntiAliasing();
    ofSetFrameRate(30);
 
    ofEnableAlphaBlending();
    
    
  
    visualControls.setName("Visual Controls");
    
    visualControls.add(nSpirals.set("Spirals", 100, 0, 100));
    visualControls.add(rotationDeg.set("Rotation Degree", 5, 1, 360));
    visualControls.add(scaleX.set("Scale X", 1.1, 0.1, 1.9));
    visualControls.add(scaleY.set("Scale Y", 1.1, 0.1, 1.9));
    visualControls.add(backgroundCol.set("Background Color", 30, 0, 255));
    visualControls.add(lineWidth.set("Line Width", 1, 0, 10));
    visualControls.add(clearAlpha.set("Alpha", 49, 0, 1000));
    
    visualControls.add(autoRotate.set("Auto Rotate",false));
    visualControls.add(rotateRate.set("Rotation Rate",0.1,0.1,2.0));
    
      gui.setup(visualControls);
   
    

}

//--------------------------------------------------------------
void ofApp::update()
{
    
    if(autoRotate==true)
    {
        rotationDeg+=rotateRate;
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
  
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(backgroundCol);
    ofSetLineWidth(lineWidth);
    ofNoFill();
    
    gui.draw();
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    for(int i=0;i<nSpirals;i++)
    {
        randomRed=(i+(int)ofRandom(255))%255;
        randomGreen=(i+(int)ofRandom(255))%255;
        randomBlue=(i+(int)ofRandom(255))%255;
        
        ofSetColor(randomRed,randomGreen,randomBlue,clearAlpha);
        ofScale(scaleX,scaleY);
        

        ofRotate(rotationDeg);
        
        ofDrawRectangle(0, 0, 20, 20);
    }
    
    ofPopMatrix();
    
    
}

//--------------------------------------------------------------
