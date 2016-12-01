#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Oscillator.hpp"
#include "Smoother.hpp"



class ofApp : public ofBaseApp

{

	public:
		void setup();
		void update();
		void draw();
        void audioOut(float* buffer, int bufferSize, int nChannels);
        void exit();
    
    ofxPanel guiA;
    ofxPanel guiSol;
    ofxPanel guiV;
    
    ofParameterGroup oddioParameters;
    ofParameterGroup visualParameters;
    
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    
    OscillatorClass oscFun;
  
    OscillatorClass osc[6]; // Set number of harmonics. Make sure all for loops that populate this array are set accordingly
    
    double currentSample;
    
    int i,k; //the reason for initializing these variables here is to avoid memory allocation on the audio thread. Check out Pete Goodlife's video on Golden Rules of Audio Programming.
    
    int sampleRate;
    
    int randomRed;
    int randomGreen;
    int randomBlue;
    int rotation;
    
    
    int randomRadius;
    
  
    
};