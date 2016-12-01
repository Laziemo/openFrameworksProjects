#include "ofApp.h"
using namespace std;
//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetFrameRate(60);
    ofSetBackgroundColor(32);
    ofSetCircleResolution(1000);
    
    sampleRate=44100;
    rotation=0;
    
    
    oscFun.setup(true);
    
   
    oddioParameters.add(oscFun.oscParameters);
    
    guiSol.setup(oscFun.solfeggioFreqs, "settings.xml",0, 700);

    
    for(int j=0; j <6; j++)
    {
        osc[j].setup(false);
       
        oddioParameters.add(osc[j].oscParameters);
        
        osc[j].harmonic=1+j*4;
        
    }
    
    guiA.setup(oddioParameters);
    
    visualParameters.add(red.set("Red",0,0,105));
    visualParameters.add(green.set("Green",0,0,105));
    visualParameters.add(blue.set("Blue",0,0,105));
    
    guiV.setup(visualParameters, "settings.xml", 1200, 10);

    
    ofSoundStreamSetup(2, 0, 44100, 64, 4); //This function must always be at the end of the setup() function.
}

//--------------------------------------------------------------
void ofApp::update()
{

//=============================================================Audio Trigger via Keyboard + Amp Envelope
    
    if(ofGetKeyPressed())
    {
      
        oscFun.amplitude.targetValue= ofLerp(oscFun.amplitude.targetValue,0.5,0.1);

        for(int g=0; g<6; g++)
        {
            
            osc[g].amplitude.targetValue = ofLerp(osc[g].amplitude.targetValue,0.5,0.5);
            
        }
    }
    
    else
    {
        
        oscFun.amplitude.targetValue = ofLerp(oscFun.amplitude.targetValue,0.0, 0.08);
        
        for(int g=0; g<6; g++)
        {
           
            osc[g].amplitude.targetValue = ofLerp(osc[g].amplitude.targetValue,0.0, 0.1);
            
        }
    }

//=============================================================Set Solfeggio Frequency
    
    if(oscFun.ut==true)
    {
        oscFun.frequency=396.0;
    }
    if(oscFun.re==true)
    {
        oscFun.frequency=417.0;
    }
    if(oscFun.mi==true)
    {
        oscFun.frequency=528.0;
    }
    if(oscFun.fa==true)
    {
        oscFun.frequency=639.0;
    }
    if(oscFun.sol==true)
    {
        oscFun.frequency=741.0;
    }
    if(oscFun.la==true)
    {
        oscFun.frequency=892.0;
    }
  
}



//--------------------------------------------------------------
void ofApp::draw()
{
    
    oscFun.update();
    
    guiA.draw();
    guiV.draw();
    guiSol.draw();
    
    
//=============================================================Fundamental Circle
    
    randomRadius=ofRandom(25);
    randomRed=ofRandom(150);
    randomGreen=ofRandom(150);
    randomBlue=ofRandom(150);
    
    ofSetColor(red+randomRed,green+randomGreen,blue+randomBlue);
    ofNoFill();
    ofSetLineWidth(12);

    ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, (ofMap(oscFun.frequency, 20, 2000, 500, 5)+randomRadius)*oscFun.amplitude.currentValue);
    
//=============================================================Harmonic Circles
    
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    rotation++;
    
    for(int m=0; m<6;m++)
    {
        
        osc[m].frequency=oscFun.frequency;
        osc[m].update();
        
       ofSetColor(ofRandom(20*m)+randomRed,ofRandom(20*m)+randomGreen,ofRandom(20*m)+randomBlue);
        
       ofSetLineWidth(m+2);
        
        
       ofRotate(rotation*m*0.2);
        
       ofDrawCircle(ofMap(osc[m].harmonic, 0, 24, ofGetWidth()*0.01, ofGetWidth()*0.3),ofMap(osc[m].harmonic, 0, 24, ofGetHeight()*0.01, ofGetHeight()*0.3), ofMap(osc[m].freak,100,10000,50,2)*osc[m].amplitude.currentValue*2);
        
        
    }
    
    
}

//--------------------------------------------------------------

void ofApp::audioOut(float *buffer, int bufferSize, int nChannels)
{
    
//=============================================================Audio Callback
    
    
    for(i=0; i<bufferSize; i++)
    {
    
        currentSample=0;
        
        
        currentSample+=oscFun.getSample();
        
        
        
        for (k=0; k<6; k++)
        {
            
        currentSample+=osc[k].getSample();
            
        }
        
       
        currentSample*=0.5; // Scales the amplitude of the final signal.
        
        buffer[i*nChannels+0]=currentSample;
        buffer[i*nChannels+1]=currentSample;
 
    }
}

//---------------------------------------------------------------

void ofApp::exit()
{
    ofSoundStreamClose();
    //Always close the soundstream on exit.
    
}