/*
  ==============================================================================

    SynthSound.h
    Created: 18 Jun 2018 9:06:36am
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound {
public:
    bool appliesToNote(int /*midiNoteNumber */)     {return true;}
    bool appliesToChannel(int /*midiChannel*/)      {return true;}
};



