#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(25);
    ofSetFrameRate(60);
    
    ofSetCircleResolution(100);
    
    n=0;
    
    gui.setup();
    
    gui.add(ang.set("Angle", 137.5, 0,360));
    gui.add(radius.set("Radius",4,2,20));
    gui.add(spread.set("Spread",6,1,15));
    gui.add(alpha.set("Alpha",100,0,300));
    gui.add(reset.set("Clear Screen",false));
    gui.add(filler.set("Fill Circles",true));
    
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    //------Reset Canvas-------
    
    ofSetBackgroundAuto(reset);
    
    if(reset==true)
    {
        n=0;
    }
    
    //------Fill/No Fill-------
    
    if(filler==false)
        ofNoFill();
    else
        ofFill();

}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    gui.draw();
    
    
//------Generate Pattern-------
    
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    theta=n*ang;
    r = spread* sqrt(n);
    
    
    x= r* cos(ofDegToRad(theta));
    y= r* sin(ofDegToRad(theta));
    
    ofSetColor(n%250+45,80+(n*2)%255, 80+(n*3)%256, alpha);
    
    ofDrawCircle(x, y, radius);
    

    n++;
    
    
  
    
}

//--------------------------------------------------------------
