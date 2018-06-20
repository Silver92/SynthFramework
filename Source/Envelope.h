/*
  ==============================================================================

    Envelope.h
    Created: 19 Jun 2018 6:26:25pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(SynthFrameworkAudioProcessor& p);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
    

private:
    
    Slider attackSlider;
    
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sliderTree;
    
    SynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
