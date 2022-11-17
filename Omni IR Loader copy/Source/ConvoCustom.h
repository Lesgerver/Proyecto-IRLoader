/*
  ==============================================================================

    ConvoCustom.h
    Created: 12 Nov 2022 11:40:31am
    Author:  Gerardo Cabrera Moran

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ConvoCustom
{
public :
    ConvoCustom();
    ~ConvoCustom();
private:
    juce::AudioFormatManager formatManager;
    juce::File file {"/Volumes/Gerardo SSD/Gerardo Stuff/Clases Curso ECT/Juce Projects/Omni IR Loader/Teaser Pack/SC-MrShall60-G12V-121-Balanced.wav"};
};
