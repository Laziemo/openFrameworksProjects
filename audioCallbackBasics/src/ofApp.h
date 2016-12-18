#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp
{

public:
		void setup();
		void update();
		void draw();
        void audioOut(float *buffer, int bufferSize, int nChannels);
        void exit();
    

    int sampleRate;
    
    float bufferSample,phase, phaseInc;
    
    float x,y,r,p, pSource;
    
    
    ofParameterGroup oscParameters;
    
    ofParameter<float> amplitude;
    ofParameter<float> freakuency;
    

    ofxPanel gui;
    
		
};
