/*
  ==============================================================================

    Convolution.h
    Created: 20 May 2022 7:10:59am
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class Convolution
{
public:
    
    Convolution();
    ~Convolution();
    
    void prepare(double inSampleRate, int inSamplesPerBlock, int inNumChannels);
    
    void process(juce::AudioBuffer<float> inBuffer);
    
private:
    
    juce::dsp::Convolution miConvo;
    juce::File CabFile;
    juce::File RoomFile;
    juce::File HTRFFile;
    juce::File impulseFile;
   // juce::dsp::Convolution RoomConvo;
    

    
};
