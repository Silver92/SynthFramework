/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGUI(p), envGUI(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
    
    addAndMakeVisible(&oscGUI);
    addAndMakeVisible(&envGUI);
    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
    
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

}

void SynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    
    const int compnentWidth = 200;
    const int compnentHeight = 200;
    
    oscGUI.setBounds(area.removeFromLeft(compnentWidth).removeFromTop(compnentHeight));
    envGUI.setBounds(area.removeFromLeft(compnentWidth).removeFromTop(compnentHeight));
    
    
}









