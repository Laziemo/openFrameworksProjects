//
//  Oscillator.cpp
//  oddioAdditive
//
//  Created by Laziem Bacteria on 29/11/16.
//
//

#include "Oscillator.hpp"

void OscillatorClass::setup(bool isFundamental)
{
    
    
    sampleRate=44100;
    
//=============================Determines wether the object created is for the fundamental frequency or harmonic
    
    if(isFundamental==true)
    {
        
    oscParameters.setName("Fundamental Controls");
    oscParameters.add(frequency.set("Fundamental", 42.0, 20.0, 852.0));
    oscParameters.add(harmonic.set("Harmonic", 1, 0, 24));
    
        amplitude.targetValue= 0.0;
        amplitude.smoother = new parameterSmoother(10, sampleRate);
        
        solfeggioFreqs.setName("Solfeggio Frequencies");
        solfeggioFreqs.add(ut.set("UT", false));
        solfeggioFreqs.add(re.set("RE", false));
        solfeggioFreqs.add(mi.set("MI", false));
        solfeggioFreqs.add(fa.set("FA", false));
        solfeggioFreqs.add(sol.set("SOL", false));
        solfeggioFreqs.add(la.set("LA", false));
      
    }
    
    if(isFundamental==false)
    {
        
    oscParameters.setName("Harmonic Controls");
    oscParameters.add(harmonic.set("Harmonic", 1, 0, 24));

       
        amplitude.targetValue= 0.0;
        amplitude.smoother = new parameterSmoother(10, sampleRate);
        
        // the two arguments taken by parameterSmoother constructor are smoothing time in ms and sample rate.
     
    }

    
    phase=0.0;
    
}

//-------------------------------------------------------------------------
void OscillatorClass::update()
{
    
//====Recall the fundamental equation for generating a sinusoid x[n]=a.sin(2pi*n*f/fs + ip); n =sample number, f =frequency, fs =sampling frequency, ip =initial phase
    
    //====Various parts of this equation are brokendown and computer separately
    
   
    freak=frequency*harmonic;
    
    phaseInc=(TWO_PI*freak)/(double)sampleRate; //not too sure why n isnt added to the computation :S, will update once I figure.
    
  
    
}


//-------------------------------------------------------------------------

double OscillatorClass::getSample()
{
 
        bufferSample=0;
    
        phase+=phaseInc; // increments from initial phase
    
        amplitude.currentValue=amplitude.smoother->process(amplitude.targetValue); //smooths amplitude changes
    
        bufferSample=amplitude.currentValue*sin(phase); // Final sin generating equation = amp*sin(phase);
   
    
    return bufferSample;
    
    
        
}


//-------------------------------------------------------------------------
