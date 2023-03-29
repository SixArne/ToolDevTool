#include "MainComponent.h"
#include "src/OBJParser.h"

//==============================================================================
MainComponent::MainComponent()
    :m_Parser{ Util::OBJParser{ "test" } }
{
    setSize (600, 400);

	
    m_Parser.ReadTextOBJFile();
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText (m_Parser.Test().c_str(), getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
