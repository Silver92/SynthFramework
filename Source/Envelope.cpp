/*
  ==============================================================================

    Envelope.cpp
    Created: 19 Jun 2018 6:26:25pm
    Author:  Silver

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p): processor(p)
{
    setSize(200, 200);
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f, 0.1);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 20);
    attackSlider.setValue(0.1f);
    addAndMakeVisible(&attackSlider);

    sliderTree = new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, "attack", attackSlider);
}

Envelope::~Envelope()
{
    sliderTree.~ScopedPointer();
}

void Envelope::paint (Graphics& g)
{
    
}

void Envelope::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    int sliderWidth = 25;
    int sliderHeight = 175;
    
    //draw sliders by reducing area from rectangle above
    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));

}





