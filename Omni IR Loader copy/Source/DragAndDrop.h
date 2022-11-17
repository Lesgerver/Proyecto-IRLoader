/*
  ==============================================================================

    DragAndDrop.h
    Created: 15 Nov 2022 4:24:02pm
    Author:  Gerardo Cabrera Moran

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class DragAndDropAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::FileDragAndDropTarget
{
public:
    
    DragAndDropAudioProcessorEditor (DragAndDropAudioProcessorEditor&);
    ~DragAndDropAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int x, int y) override;

private:
    
    juce::String fileName {""};
    juce::String filePath {""};
    juce::String numChannels {""};

    DragAndDropAudioProcessorEditor& audioProcessor;
    
    juce::AudioFormatManager formatManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DragAndDropAudioProcessorEditor)
};
