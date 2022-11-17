/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OmniIRLoaderAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    OmniIRLoaderAudioProcessorEditor (OmniIRLoaderAudioProcessor&);
    ~OmniIRLoaderAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    juce::Slider lowCut;
    
    juce::Slider highCut;
    
    juce::ComboBox angles;
    
    juce::ToggleButton cabSwitch;
    
    juce::ToggleButton spatialSwitch;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowCutAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> higCutAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> anglesAttach;
    
    //std::unique_ptr<juce::AudioProcessorValueTreeState::ToggleButtonAttachment> cabSwitch;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::ToggleButtonAttachment> spatialSwitch;

    OmniIRLoaderAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OmniIRLoaderAudioProcessorEditor)
};
