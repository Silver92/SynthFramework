/*
  ==============================================================================

    Filter.h
    Created: 19 Jun 2018 8:01:42pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter();
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
