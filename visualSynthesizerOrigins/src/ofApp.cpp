#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(22);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    showGui=true;
    
    gui.setup();
    gui.setName("Parameters");
    
    
    global.setup();
    global.setName("Global");
    
    global.add(scaleG.set("Global Scale", 1, 0.0,1.0));
    global.add(rotG.set("Global Rotate", 0, -180, 180));
    
    
    dimension.setup();
    dimension.setName("Dimensional Settings");
    
    dimension.add(countX.set("Count-X",2,0,200));
    dimension.add(tran.set("Traslation-X",100,0,200));
    dimension.add(rotX.set("Twist-X",0,-90,90));
    
    dimension.add(countY.set("Count-Y", 2, 0, 50));
    dimension.add(stepY.set("Translation-Y", 100, 0, 200));
    dimension.add(rotY.set("Twist-Y", 0, -90, 90));
    dimension.add(pinchY.set("Pinch", 0, 0, 30));
    
    dimension.add(size.setup("Scale",ofVec2f(0.52,0.52),ofVec2f(0,0),ofVec2f(20,20)));
    
    
    character.setup();
    character.setName("Characteristics");
    
    character.add(random.set("Randomize", false));
    character.add(red.set("Red",125,0,255));
    character.add(green.set("Green",155,0,255));
    character.add(blue.set("Blue",200,0,255));
    character.add(alpha.set("Alpha",5,0,500));
    character.add(width.set("Line-Width",1,0,5));
    
    
    
    primitive.setup();
    primitive.setName("Primitives");
    
    primitive.add(shiftY.set("Shift-Y", 0, -1000, 1000));
    primitive.add(rotL.set("Rotate Local", 0, -180, 180));
    primitive.add(type.setup("Type", true));
    primitive.add(fill.setup("Fill", true));
    
    
    gui.add(&global);
    gui.add(&dimension);
    gui.add(&character);
    gui.add(&primitive);
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if(showGui)
    gui.draw();
    
    ofPushMatrix();
    //-----O-----
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    float scl=pow(scaleG,4.0f);
    ofScale(scaleG,scaleG);
    ofRotate(rotG);
    
    matrixPattern();
    
    //-----O-----
    ofPopMatrix();
    
}

//--------------------------------------------------------------

void ofApp::stripePattern()
{
    
    
    if(fill)
    ofFill();
    else
    ofNoFill();
    
    
    ofSetLineWidth(width);
    
    
    for(int i=-countX;i<=countX;i++)
    {
        
        if(random)
        ofSetColor(ofRandom(red),ofRandom(green), ofRandom(blue),alpha);
        else
        ofSetColor(red,green,blue,alpha);
        
        ofPushMatrix();
        //-----O-----
        
        ofTranslate(i*tran,0);
        ofRotate(i*rotX);
        
        ofTranslate(0,shiftY);
        ofRotate(rotL);
        
        ofScale(size->x,size->y);
        
        if(type)
        ofDrawTriangle(0,0,-50,100,50,100);
        else
        ofDrawRectangle(-50,-50,100,100);
        //-----O-----
        ofPopMatrix();
        
    }
}
//--------------------------------------------------------------

void ofApp:: matrixPattern()
{
    
    for(int j= -countY; j<=countY; j++)
    {
        ofPushMatrix();
        //-----O-----
        if(countY>0)
        {
            float scl= ofMap(j,-countY, countY, 1-pinchY,1);
            ofScale(scl,scl);
        }
        
        ofTranslate(0, j*stepY);
        ofRotate(j*rotY);
        stripePattern();
        
        //-----O-----
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key)
{
    
    if( key == 'z')
    showGui= !showGui;
    
    if( key == OF_KEY_RETURN)
    ofSaveScreen("videoSynth_Screenshot" + ofToString(ofRandom(0, 1000), 0) + ".png");
    
}
//--------------------------------------------------------------


