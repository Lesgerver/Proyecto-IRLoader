/*
  ==============================================================================

    ConvoCustom.cpp
    Created: 12 Nov 2022 11:40:31am
    Author:  Gerardo Cabrera Moran

  ==============================================================================
*/

#include "ConvoCustom.h"


ConvoCustom::ConvoCustom()
{
    //void AudioFormatManager::registerBasicFormats    ( )
    formatManager.registerBasicFormats();
    //juce::File() file;
    juce::AudioFormatReader* reader = formatManager.createReaderFor(file);

    int lenght = reader -> lengthInSamples;
    DBG(lenght);
    
}
ConvoCustom::~ConvoCustom()
{
    
}
