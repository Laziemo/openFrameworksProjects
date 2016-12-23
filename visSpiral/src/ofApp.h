#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		
    ofxPanel gui;
    
    
    ofParameterGroup visualControls;
    
    ofParameter<int> nSpirals;
    ofParameter<float> rotationDeg;
    ofParameter<float> scaleX;
    ofParameter<float> scaleY;
    ofParameter<int> backgroundCol;
    ofParameter<int> lineWidth;
     ofParameter<float> clearAlpha;
    ofParameter<bool> autoRotate;
    ofParameter<float> rotateRate;
   
    
    int randomRed;
    int randomGreen;
    int randomBlue;
    
    float time;
    float timeScale;
    float noise;
   
    
    
    
		
};
