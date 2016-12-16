#include "ofApp.h"

//=============================================================================================================


void ofApp::setup()
{
    ofBackground(15);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    
    ofSetCircleResolution(100);
    ofSetSphereResolution(100);
   
//    gui.setup();
//    gui.add(rate.set("Rate", 0.8, 0, 1.0));


    ambience.load("ambience.ogg");
    cbl.load("Carbon_Based_LifeForms-Photosynthesis.mp3");
    ambience.play();
    cbl.play();
    
    title.load("Xenotron.ttf", 16);

    
    //===FFT===
    
    
    fftSmooth = new double [8192];
    fftScaled= 0.0;
    
    for(int i=0; i<8192; i++)
    {
        fftSmooth[i]=0.0;
    }
    
    bands=64;
    
    
    //=======
    
    
    
    
    len=100.00;
    angle=0.3455;
    val=100;
    rate=0.84;
    
    
}

//=============================================================================================================

void ofApp::update()
{

    //=====FFT======
    
    
    ofSoundUpdate();
    
    float *value= ofSoundGetSpectrum(bands);
    
    //Returns amplitude values from 0.0 to 1.0 for each band
    
    for(int i=0; i<bands; i++)
    {
        
        fftSmooth[i]*=rate;
        
        //Higher rates decrease chances of passing next condition.
        
        if (fftSmooth[i]< value[i])
        {
            fftSmooth[i]=value[i];
            
            //This is why high rates create less circles due to less smoothing, and low rates create many circles each representing a band of the FFT ("the true signal"). A lot like compression theory.
        }
        
        
        
    }
    

    
}

//=============================================================================================================


void ofApp::draw()
{
    
//    gui.draw();
    
    title.drawString("Carbon Based Lifeforms", 25, 50);
    title.drawString("Photosynthesis", 25, 80);
    
    for(int p=0; p<800; p++)
    {
        
        odd=ofMap(fftSmooth[p%65], 0, 1, 0,30);
        oddB=ofMap(fftSmooth[p%65], 0, 1, 0,10);
        col=ofMap(fftSmooth[p%65], 0, 1, 0,255);
        
        drop[p].fall();
        drop[p].draw(oddB+10, oddB);
        
        ofPushMatrix();
        if(p%2==0||p%5==0)
        {
            ofNoFill();
            ofSetColor(120,col+43,col,70);
        }
        else
        {
            ofSetColor(120,col+43,col,odd-10);
        }
       
        ofDrawCircle(220, 180, odd);
        
        ofPopMatrix();
    }
    
    
    addTree(0.05, -70, 0.2);
    addTree(0.09, -50, 0.0);
    addTree(0.17, +80,-0.1);
    addTree(0.20, -70, 0.3);
    addTree(0.25, -20, 0.0);
    addTree(0.30, -50, 0.256);
    addTree(0.38, +20, 0.0);
    addTree(0.48, -30, 0.0);
    addTree(0.56, -60, 0.43);
    addTree(0.62, +150, 0.0);
    addTree(0.65, -10, -0.068);
    addTree(0.75, -34, -0.0);
    addTree(0.80, 54, -0.0);
    addTree(0.86, -64, 0.2);
    addTree(0.91, -24, 0.1);

    
    
}


//=============================================================================================================



void ofApp::addTree(float pos, int h, float spr)
{
    ofPushMatrix();
    ofTranslate(ofGetWidth()*pos, ofGetHeight());
    branch(len+h,angle+spr);
    ofPopMatrix();
}

//=============================================================================================================



void ofApp::branch(float len, float angle)
{
    
    
    
    ofSetLineWidth(2);
    
    r=ofRandom(200);
    g=ofRandom(125);
    b=ofMap(ofNoise(val), 0, 1, 0, 255);
    
    val+=10;
    
    ofSetColor((int)r,100+(int)g,(int)b);
    
    ofDrawLine(0, 0, 0, -len);
    
    
    ofTranslate(0, -len);
    
    //==RIGHT BRANCH==
    
    ofPushMatrix();
    ofRotate(ofRadToDeg(angle));
    if(len>4)
        branch(len*0.70, angle);
    ofPopMatrix();
    
    //==LEFT BRANCH==
    
    
    ofPushMatrix();
    ofRotate(ofRadToDeg(-angle));
    if(len>4)
        branch(len*0.70, angle);
    ofPopMatrix();
    
    
}
//=============================================================================================================


