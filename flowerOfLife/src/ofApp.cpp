#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    ofSetFrameRate(1);
    
    ofBackground(36);
    ofSetCircleResolution(200);
    
    title.load("Xenotron.ttf", 35);
    
    nucleus.setup();
    
    max=335916;
    //6^3 + 36= 252
    //6^4 + 252= 1548
    //6^5 + 1548= 9324
    //6^6 + 9324= 55980
    //6^7 + 55980= 335916
    
    r=nucleus.R;
    orX=nucleus.oX;
    orY=nucleus.oY;
    
    
}

//--------------------------------------------------------------
void ofApp::update()

{
    
    
    
    //---Nucleus Dependant---Seed of Life
    
    for(int i=0; i<6; i++)
    {
        
        embryo[i].nX=nucleus.oX + ( cos ( (i*(PI/3)) ) * nucleus.R );
        embryo[i].nY=nucleus.oY + ( sin ( (i*(PI/3)) ) * nucleus.R );
        
    }
    
    //---Embryo Dependant---Egg of Life---
    
    jump=-1;
    
    for(int j=0; j<36; j++)
    {
        p=j%6;
        if(p==0)
            jump++;
        
        globule[j].nX=embryo[jump].nX +( cos( (j*(PI/3)) )*nucleus.R);
        globule[j].nY=embryo[jump].nY +( sin( (j*(PI/3)) )*nucleus.R);
        
        
    }
    
    //---Globule Dependant/Independant---Flower of Life---
    
    fly=-1;
    
    for (int k = 36; k<max; k++)
        
    {
        
        
        q=k%6;
        
        if(q==0)
        {
            fly++;
        }
        
        
        globule[k].nX=globule[fly].nX + ( cos( (q*(PI/3)) )*nucleus.R);
        globule[k].nY=globule[fly].nY + ( sin( (q* (PI/3)) )*nucleus.R);
        
        
    }
    
    
    
    
    
}

//--------------------------------------------------------------

void ofApp::draw()
{
    
    
    
    ofPushMatrix();
    ofSetColor(ofRandom(255),215,ofRandom(255),111);
    title.drawString("Flower of Life", ofGetWidth()*0.18, 50);
    ofPopMatrix();
    
    
    
    nucleus.draw();
    
    
    for(int i=0; i<6; i++)
    {
        
        embryo[i].draw(embryo[i].nX, embryo[i].nY, nucleus.R);
        
    }
    
    for(int q=0; q<36; q++)
    {
        
        globule[q].draw(globule[q].nX, globule[q].nY, nucleus.R);
        
    }
    
    for(int k = 36; k<max; k++)
        
    {
        
        globule[k].draw(globule[k].nX, globule[k].nY, nucleus.R);
        
        
    }
    
    //----------------------Fruit of Life------------------
    
    ofSetLineWidth(8);
    ofSetColor(ofRandom(150),ofRandom(64,150),123,92);
    //--Across X
    ofDrawCircle(orX -(2*r), orY, r);
    ofDrawCircle(orX +(2*r), orY, r);
    
    ofDrawCircle(orX -(4*r), orY, r);
    ofDrawCircle(orX +(4*r), orY, r);
    
    ofDrawCircle(orX -(6*r), orY, r);
    ofDrawCircle(orX +(6*r), orY, r);
    //---Y+- 1 Across X
    ofDrawCircle(orX +r, orY-(r*1.732), r);
    ofDrawCircle(orX -r, orY-(r*1.732), r);
    ofDrawCircle(orX +r, orY+(r*1.732), r);
    ofDrawCircle(orX -r, orY+(r*1.732), r);
    //---Y+- 2 Across X
    ofDrawCircle(orX +(2*r), orY-(2*r*1.732), r);
    ofDrawCircle(orX -(2*r), orY-(2*r*1.732), r);
    ofDrawCircle(orX +(2*r), orY+(2*r*1.732), r);
    ofDrawCircle(orX -(2*r), orY+(2*r*1.732), r);
    //---Y+- 3 Across X
    ofDrawCircle(orX +(3*r), orY-(3*r*1.732), r);
    ofDrawCircle(orX -(3*r), orY-(3*r*1.732), r);
    ofDrawCircle(orX +(3*r), orY+(3*r*1.732), r);
    ofDrawCircle(orX -(3*r), orY+(3*r*1.732), r);
    
    //----------------------Metatron------------------
    
    
    //------HEX.O------
    
    for(int m=1;m<4;m++)
    {
        ofBeginShape();
        ofSetLineWidth(3);
        ofSetColor(m*35, ofRandom(m*70),m*60);
        
        ofVertex(orX -(2*m*r), orY);
        
        ofVertex(orX -(m*r), orY-(m*r*1.732));
        ofVertex(orX +(m*r), orY-(m*r*1.732));
        
        ofVertex(orX +(2*m*r), orY);
        
        ofVertex(orX +(m*r), orY+(m*r*1.732));
        ofVertex(orX -(m*r), orY+(m*r*1.732));
        
        
        ofEndShape(true);
        
        
        //---TRI.O---
        
        ofBeginShape();
        ofSetLineWidth(2);
        ofSetColor(211);
        
        ofVertex(orX -(m*r), orY+(m*r*1.732));
        
        ofVertex(orX -(m*r), orY-(m*r*1.732));
        
        ofVertex(orX +(2*m*r), orY);
        
        
        ofEndShape(true);
        
        //---TRI.1---
        
        ofBeginShape();
        ofSetLineWidth(1);
        ofSetColor(211);
        
        ofVertex(orX -(2*m*r), orY);
        
        ofVertex(orX +(m*r), orY-(m*r*1.732));
        
        ofVertex(orX +(m*r), orY+(m*r*1.732));
        
        
        ofEndShape(true);
        
    }
    
    
    
    //---------------------SatUrN-------------------------
    
    
    ofSetColor(ofRandom(255));
    ofSetLineWidth(1);
    ofDrawCircle(nucleus.oX,nucleus.oY,(nucleus.R*8));
    
    ofSetColor(135);
    ofSetLineWidth(2);
    ofDrawCircle(nucleus.oX,nucleus.oY,(nucleus.R*8.25));
    
    
    ofSetColor(ofRandom(92), 200, ofRandom(234),70);
    ofSetLineWidth(3);
    ofDrawCircle(nucleus.oX,nucleus.oY,(nucleus.R*8.5));
    
    //    Drawing all the circles
    
}


//--------------------------------------------------------------

