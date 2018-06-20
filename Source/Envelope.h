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
class Envelope    : public Component, public Slider::Listener
{
public:
    Envelope(SynthFrameworkAudioProcessor& p);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;

private:
    
    SynthFrameworkAudioProcessor& processor;
    
    Slider attackSlider;
    
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sliderTree;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
