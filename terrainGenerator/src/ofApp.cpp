#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    ofSetBackgroundColor(36);
    ofSetFrameRate(60);
    
    
    scl=10;
    
    w=1200;
    h=1200;
    
    rows=w/scl;
    cols=h/scl;
    
    flying=0;

    
    
}

//--------------------------------------------------------------
void ofApp::update()
{
   
    flying-=0.051;
    
    yOff=flying;
    for(int y=0; y<rows; y++)
    {
        xOff=0.0;
        for(int x=0; x<cols; x++)
        {
            terrain[x][y]=ofMap(ofNoise(xOff,yOff), 0,1,-20,40);
            xOff+=0.1;
        }
        yOff+=0.1;
    }
    
   
    


}

//--------------------------------------------------------------
void ofApp::draw()
{

   
    ofNoFill();
    ofSetLineWidth(2);
  
    
    ofTranslate(ofGetWidth()*0.5,ofGetHeight()*0.4);
    ofTranslate(-w/2, -h/8);
    
    

 

    ofRotateX(60);

    
    for(int y=0; y<rows; y++)
    {

        
        ofBeginShape();
   
        
        
    for(int x=0; x<cols; x++)
    {
        
        ofSetColor(ofMap(terrain[x][y], -20, 40, 255,0));
     
      
        ofVertex(x*scl, (y)*scl, terrain[x][y]);
        ofVertex(x*scl, (y+1)*scl,terrain[x][y+1]);
    
        ofVertex(x*scl, (y)*scl,terrain[x][y]);
        ofVertex((x+1)*scl, (y)*scl,terrain[x+1][y]);
        
        ofVertex(x*scl, (y+1)*scl,terrain[x][y+1]);
        ofVertex((x+1)*scl, (y)*scl,terrain[x+1][y]);
        
        ofVertex((x+1)*scl, (y+1)*scl,terrain[x+1][y+1]);
        
        
       
    }
       
        
        ofEndShape();
    }
    

}

//--------------------------------------------------------------

