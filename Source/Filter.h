/*
  ==============================================================================

    Filter.h
    Created: 19 Jun 2018 8:01:42pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(SynthFrameworkAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider filterCutoff;
    Slider filterRes;
    
    ComboBox filterMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal;
    
    SynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
