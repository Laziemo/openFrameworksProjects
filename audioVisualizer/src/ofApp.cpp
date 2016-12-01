#include "ofApp.h"
using namespace std;

//-----------------------------------------------------------------------------------------------

void ofApp::setup()
{
    
    ofSetBackgroundColor(25);
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    
    title.loadFont("avenir-book.ttf", 12);
    ofSetColor(0, 220, 150);
    title.drawString("Amen Break", 900, 100);// track title
    
    track.load("amen_brother.wav"); //replace with your own audio filename located in apps/myApps/fft_Basics/bin/data
    track.setLoop(true);
    
    fftSmooth = new double [8192];
    fftScaled= 0.0;
    
    for(int i=0; i<8192; i++)
    {
        fftSmooth[i]=0.0;
    }
    
    bands=32;
    
    
    gui.setup();
    
    play.addListener(this, &ofApp::playPressed);
    stop.addListener(this, &ofApp::stopPressed);
    
    
    gui.add(play.setup("Play", false));
    gui.add(stop.setup("Stop", true));
    gui.add(volume.setup("Volume", 0.5, 0.0, 1.0));
    
    gui.add(rate.setup("Rate", 0.5, 0.0, 1.0));
    gui.add(center.setup("Centre-Size", 0.1, 0.0, 5));
    gui.add(spread.setup("Spread", 1, 0.0, 10.0));
    gui.add(bandRisk.setup("Bands", 32, 0, 128));
    
    
    gui.add(red.setup("Red", 32, 0, 255));
    gui.add(green.setup("Green", 32, 0, 255));
    gui.add(blue.setup("Blue", 32, 0, 255));
    
    
    gui.add(rotateX.set("X", 0.0, -0.1, 0.1));
    gui.add(rotateY.set("Y", 0.0, -0.1, 0.1));
    gui.add(rotateZ.set("Z", 0.0, -0.1, 0.1));
    
    
    rotationX=0.0;
    rotationY=0.0;
    rotationZ=0.0;
    
    
}

//--------------------------------------------------------------------------------------------------
void ofApp::update()
{
    
    ofSoundUpdate();
    
    bands=bandRisk;
    
    float *value= ofSoundGetSpectrum(bands); //Returns amplitude values from 0.0 to 1.0 for each band
    
    for(int i=0; i<bands; i++)
    {
        
        fftSmooth[i]*=rate;//Higher rates decrease chances of passing next condition.
        
        if (fftSmooth[i]< value[i])
        {
            fftSmooth[i]=value[i];//This is why high rates create less circle due to less smoothing, and low rates create many circles each representing a band of the FFT ("the true signal"). A lot like compression theory.
        }
        
        
        //        cout<<"fftSmooth["<<i<<"]= "<< fftSmooth[i]<<endl;
        
    }
    
    
    rotationX=rotationX+rotateX;
    rotationY=rotationY+rotateY;
    rotationZ=rotationZ+rotateZ;
    
    // Infinitely Incrementing rotations: cycling every 360
    
    track.setVolume(volume);
    
    
}

//--------------------------------------------------------------------------------------------------

void ofApp::draw()
{
    
    gui.draw();
    
    
    ofSetCircleResolution(1000);
    ofNoFill();
    ofSetLineWidth(2);
    
    
    for(int i=0; i<bands; i++)
    {
        
        
        fftScaled=fftSmooth[i]*1000; //FFT Scaling
        
        
        
        fftColorMod=(fftScaled*1000);
        fftColorMod=fftColorMod%255; // Scaling to fit within the range of 225 to adjust color
        
        
        ofSetColor(red+fftColorMod, green+fftColorMod,blue+fftColorMod);
        
        
        ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.7,(center*i+ fftScaled*ofRandom(0,spread))); //Audio FFT controlling the radius of the circle.
        
        
        
        ofRotateX(rotationX);
        ofRotateY(rotationY);
        ofRotateZ(rotationZ);
        // Rotation
        
    }
    
    
    
    
}

//--------------------------------------------------------------------------------------------------

void ofApp::playPressed()
{
    
    track.play();
}


//--------------------------------------------------------------------------------------------------

void ofApp::stopPressed()
{
    
    track.stop();
}

