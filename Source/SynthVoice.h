/*
  ==============================================================================

    SynthVoice.h
    Created: 18 Jun 2018 9:06:47am
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice {
public:
    bool canPlaySound (SynthesiserSound * sound ){
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=========================================================================
    
    void getParam (float* attack) {
        env1.setAttack(double(*attack));
    }
    
    //=========================================================================
    
    void getOscType(float* selection) {
        theWave = *selection;
    }
    
    //=========================================================================
    
    double setOscType() {
        if( theWave == 0)   {return osc1.sinewave(frequency);}
        if( theWave == 1)   {return osc1.saw(frequency);}
        if( theWave == 2)   {return osc1.square(frequency);}
        else                {return osc1.sinewave(frequency);}
    }
    
    //=========================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {
        
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }
    
    //=========================================================================
    
    void stopNote (float velocity, bool allowTailOff) {
        
        env1.trigger = 0;
        allowTailOff = true;
        
        if(velocity == 0) {clearCurrentNote();}
    }
    
    //=========================================================================
    
    void pitchWheelMoved (int newPitchWheelValue) {
        
    }
    
    //=========================================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue) {
        
    }
    
    //=========================================================================
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) {
//        env1.setAttack(0.2);
        env1.setDecay(500);
        env1.setSustain(0.4);
        env1.setRelease(2000);
        
        for(int sample = 0; sample < numSamples; ++sample) {
            double theSound = env1.adsr(setOscType(), env1.trigger) * level;
            for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, theSound);
            }
            ++startSample;
        }
    }
    
    //=========================================================================
private:
    double level;
    double frequency;
    int theWave;
    
    maxiOsc osc1;
    maxiEnv env1;
    
    
    
    
    
    
    
};
