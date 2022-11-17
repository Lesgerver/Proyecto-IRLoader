/*
  ==============================================================================

    Convolution.cpp
    Created: 20 May 2022 7:10:59am
    Author:  Jesús Valdez

  ==============================================================================
*/

#include "Convolution.h"

Convolution::Convolution(){}

Convolution::~Convolution(){}

void Convolution::prepare(double inSampleRate, int inSamplesPerBlock, int inNumChannels)
{
    // GET PATH PARA IMPULSO
    //auto impulsePath = (juce::File::getSpecialLocation(juce::File::userDesktopDirectory)).getFullPathName() + "/impulse.wav";
    
    //impulseFile = juce::File(impulsePath);
    
    //auto impulsePath = (juce::File::getSpecialLocation(juce::File::userDesktopDirectory)).getFullPathName() + "/impulse.wav";
    
    
    // INICIALIZAR SPEC
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = inSampleRate;
    spec.maximumBlockSize = inSamplesPerBlock;
    spec.numChannels = inNumChannels;
    
    // INICIALIZAR CONVOLUCION
    miConvo.reset();
    miConvo.prepare(spec);
    
    // CARGAR IMPULSO SELECCIONADO
    
    miConvo.loadImpulseResponse(impulseFile.getFullPathName(),
                                juce::dsp::Convolution::Stereo::no,
                                juce::dsp::Convolution::Trim::yes,
                                impulseFile.getSize());
    
    /*miConvo.loadImpulseResponse (BinaryData::Fredman_Straight_wav,
                                    BinaryData::Fredman_Straight_wavSize,
                                    juce::dsp::Convolution::Stereo::yes,
                                    juce::dsp::Convolution::Trim::yes,
                                    0,
                                    juce::dsp::Convolution::Normalise::yes);*/
}

void Convolution::process(juce::AudioBuffer<float> inBuffer)
{
    juce::dsp::AudioBlock<float> block (inBuffer);
    juce::dsp::ProcessContextReplacing<float> context (block);
    miConvo.process(context);
}
