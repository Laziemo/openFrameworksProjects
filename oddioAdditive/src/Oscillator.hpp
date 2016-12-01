//
//  Oscillator.hpp
//  oddioAdditive
//
//  Created by Laziem Bacteria on 29/11/16.
//
//

#ifndef Oscillator_hpp
#define Oscillator_hpp

#include "ofMain.h"
#include "Smoother.hpp"

#endif /* Oscillator_hpp */

//=============================================================Parameter Smoothing Variables and Type
struct smoothValue
{
    double targetValue;
    double currentValue;
    
    parameterSmoother* smoother;
};

//--------------------------------------------------------------

class OscillatorClass
{
    
public:
    void setup(bool isFundamental);
    double getSample();
    void update();

    ofParameterGroup oscParameters;
    
    ofParameter<float> frequency;
    
    ofParameterGroup solfeggioFreqs;
    
    ofParameter<bool> ut;
    ofParameter<bool> re;
    ofParameter<bool> mi;
    ofParameter<bool> fa;
    ofParameter<bool> sol;
    ofParameter<bool> la;
   
    ofParameter<int> harmonic;
    
    float freak;
    double phase;
    double phaseInc;
    
    int sampleRate;
    
    double bufferSample;
    
    smoothValue amplitude; // any variable which requires smoothing must be of type smoothValue and follow the same syntax  
};
