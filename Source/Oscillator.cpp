/*
  ==============================================================================

    Oscillator(2).cpp
    Created: 19 Jun 2018 12:21:42pm
    Author:  Silver

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) :processor(p)
{
    setSize(200,  200);
    
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.treeState, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box) {
    
}
