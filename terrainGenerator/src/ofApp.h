#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    
    int scl;
    int w,h,cols, rows, r;
    

    float terrain[200][200];
    

    float xOff,yOff, flying,a;
    
    
};
