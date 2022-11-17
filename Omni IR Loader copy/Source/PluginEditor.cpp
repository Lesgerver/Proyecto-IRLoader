/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OmniIRLoaderAudioProcessorEditor::OmniIRLoaderAudioProcessorEditor (OmniIRLoaderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //------Crea un slider rotatorio en la GUI para el low cut
    addAndMakeVisible(lowCut);
    lowCut.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    lowCut.setRange(5.0, 20.0);
    lowCut.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
   
    //------Crea un slider rotatorio en la GUI para el high cut
       addAndMakeVisible(highCut);
       highCut.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
       highCut.setRange(5.0, 20.0);
       highCut.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    
    //------Crea un tickbox para activar o desactivar la convo del Cab
    addAndMakeVisible(cabSwitch);
    //cabSwitch.onClick = [this] { updateToggleState (&cabSwitch,   "Cab on"); };
    //cabSwitch.setToggleState(false, false);
    //cabSwitch.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>);
    //cabSwitch.setTitle("Cab on");
    
     //------Crea un tickbox para activar o desactivar de las HRTF's
    //addAndMakeVisible(spatialSwitch);
    //spatialSwitch.setToggleState(false, false);
    //spatialSwitch.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>);
    //spatialSwitch.setTitle(<#const String &newTitle#>);
    
    //------Crea un combobox para seleccionar las HRTF's
    addAndMakeVisible(angles);
    //spatialSwitch.setToggleState(false, false);
    //spatialSwitch.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>);
    //spatialSwitch.setTitle(<#const String &newTitle#>);
    
    
    //-------Enlaza los controles de la GUI con los parámetros del AudioProcessor---------------
    lowCutAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "lowCut",lowCut);
    higCutAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "highCut",highCut);
    anglesAttach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "angles",angles);
    
    //cabSwitchAttach = std::make_unique<juce::AudioProcessorValueTreeState::ToggleSwitchAttachment>(audioProcessor.apvts, "cabSwitch", cabSwitch);
    setSize (400, 300);
    
    
    
}

OmniIRLoaderAudioProcessorEditor::~OmniIRLoaderAudioProcessorEditor()
{
}

//==============================================================================
void OmniIRLoaderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::red);
    g.setFont (15.0f);
    g.drawFittedText ("Omni IR Loader", getLocalBounds(), juce::Justification::centredTop, 1);
}

void OmniIRLoaderAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    lowCut.setBounds(15, 200, 75, 75);
    highCut.setBounds(75, 200, 75, 75);
    //highCut.setBounds(<#int x#>, <#int y#>, <#int width#>, <#int height#>)
    cabSwitch.setBounds(50, 50, 350, 250);
    spatialSwitch.setBounds(200, 50, 400, 300);
    angles.setBounds(250, 200, 100, 30);
}
