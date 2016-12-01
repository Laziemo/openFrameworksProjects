//
//  Smoother.hpp
//  oddioAdditive
//
//  Created by Laziem Bacteria on 30/11/16.
//

#pragma once
#ifndef Smoother_hpp
#define Smoother_hpp

#include "ofMain.h"

#endif /* Smoother_hpp */

//=============================================================Parameter Smoothing Filter

class parameterSmoother
{
    
private:
    
    double a;
    double b;
    double z;
    
public:
    
    parameterSmoother(float smoothingTime, int sampleRate)
    {
        sampleRate=44100;
        
        a= exp(-TWO_PI/ (smoothingTime*0.001*(double)sampleRate));
        b=1.0-a;
        z=0.0;
        
    }


    
    inline float process(double input)
    {
        
            z=(input*b)+(z*a);
            return z;
    
    }
    
//=======================================I dont fully understand the intuition behind these filters but it creates a smooth curve between changing values - sort of like interpolation? but a filter which sweeps at a given smoothing time. 
    
    
};