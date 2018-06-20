/*
  ==============================================================================

    Oscillator(2).h
    Created: 19 Jun 2018 12:21:42pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator    : public Component, private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    
    SynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
