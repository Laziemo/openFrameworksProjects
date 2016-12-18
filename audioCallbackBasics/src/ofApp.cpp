#include "ofApp.h"

//------------------------------------------
void ofApp::setup()
{
    
    ofSetBackgroundColor(36);
    ofSetCircleResolution(100);
    ofSetFrameRate(60);
    
    
    
    


    oscParameters.setName("Oscillator Controls");
    oscParameters.add(freakuency.set("Freakuency",192, 20, 2000));
    oscParameters.add(amplitude.set("Amplitude",0.1, 0.0, 1.0));
    
    gui.setup(oscParameters);
    
    ofxGuiSetFont("Xenotron.ttf", 8);
    
    sampleRate=48000;
    
    phase = 0.0;
    
    ofSoundStreamSetup(2, 0,sampleRate, 128, 4);
    
}

//---------------------------------------

void ofApp::update()
{

    //==Visual CounterPart of Audio
    
    pSource=(TWO_PI*freakuency)/sampleRate;
    
    p+= pSource;
    
    x=ofMap(sin(p), -1,1, 50, ofGetWidth()-50);
    y=ofMap(cos(p), -1,1, 50, ofGetHeight()-50);
    r=ofMap(freakuency,20, 2000, 50, 10);
    

    
}

//-----------------------------------
void ofApp::draw()
{
    
    gui.draw();
    

    ofSetColor(ofRandom(256), ofRandom(256), ofRandom(256), 92);
    ofFill();
    ofDrawCircle(x, y, r);
    
    ofNoFill();
    ofSetLineWidth(5);
    ofDrawCircle(x, y, r);
    
    ofSetColor(ofRandom(256), ofRandom(256), ofRandom(256), 192);
    
    ofSetLineWidth(2);
    ofDrawCircle(x, y, r/1.2);
    
    ofSetLineWidth(3);
    ofDrawCircle(x, y, r/2);
    
    ofSetLineWidth(4);
    ofDrawCircle(x, y, r/3);
    
    
    
}

//------AUDIO CALLBACK FUNCTION-------


void ofApp::audioOut(float *output, int bufferSize, int nChannels)
{
    
    for(int i=0; i<bufferSize; i++)
        
    {
       bufferSample=0.00;
       phaseInc=(TWO_PI*freakuency)/(float)sampleRate;
 
      
       phase += phaseInc;
        
       bufferSample=amplitude * sin(phase);
        
       bufferSample*=0.7; //Scales overall output to 0.5 - sort of works as a Limiter without doing any compression.
        
        output[i*nChannels + 0]= bufferSample;
        output[i*nChannels + 1]= bufferSample;
        
    }
}


//-------------------------------------


void ofApp::exit()
{
    ofSoundStreamClose();  //Always close ofSoundStream
    
}