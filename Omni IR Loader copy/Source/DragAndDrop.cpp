/*
  ==============================================================================

    DragAndDrop.cpp
    Created: 15 Nov 2022 4:24:02pm
    Author:  Gerardo Cabrera Moran

  ==============================================================================
*/

#include "DragAndDrop.h"
//#include "PluginProcessor.h"
#include "PluginEditor.h"

DragAndDropAudioProcessorEditor::DragAndDropAudioProcessorEditor (DragAndDropAudioProcessorEditor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

DragAndDropAudioProcessorEditor::~DragAndDropAudioProcessorEditor(){}

void DragAndDropAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::white);
    
    g.setColour(juce::Colours::black);
    
    g.drawText(fileName, 0, 0, 400, 100, juce::Justification::centred);
    g.drawText(filePath, 0, 100, 400, 100, juce::Justification::centred);
    g.drawText("Number of Channels: " + numChannels, 0, 200, 400, 100, juce::Justification::centred);
}

void DragAndDropAudioProcessorEditor::resized()
{
    formatManager.registerBasicFormats();
}

bool DragAndDropAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray& files)
{
    for(auto file : files)
    {
        if(file.contains(".wav") || file.contains(".mp3") || file.contains(".aiff"))
        {
            return true;
        }
    }
    
    return false;
}

void DragAndDropAudioProcessorEditor::filesDropped (const juce::StringArray& files, int x, int y)
{
    for(auto file : files)
    {
        if(isInterestedInFileDrag(file))
        {
            auto myFile = std::make_unique<juce::File>(file);
            fileName = myFile->getFileNameWithoutExtension() + myFile->getFileExtension();
            filePath = myFile->getFullPathName();
            
            auto fileReader = formatManager.createReaderFor (*myFile);
            auto channelLayout = fileReader->getChannelLayout();
            numChannels = juce::String (channelLayout.size());
        }
    }
    
    repaint();
}



