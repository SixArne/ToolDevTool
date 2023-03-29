#include "MainComponent.h"
#include "src/OBJParser.h"

//==============================================================================
MainComponent::MainComponent()
    :m_Parser{ Util::OBJParser{ "test" } }
{
    setSize (600, 400);
    m_TxtButton.setButtonText("Click me");
    addAndMakeVisible(m_TxtButton);
    m_TxtButton.onClick = [this]()
    {
        SelectFile();
    };
	
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
    m_TxtButton.setBounds(10, 10, 300, 30);
}

void MainComponent::SelectFile()
{
	m_FileChooser = std::make_unique<FileChooser>(
        "Please select the file to load...",
		File::getSpecialLocation(File::userHomeDirectory),
		"*.obj"
		);

	auto folderChooserFlags = FileBrowserComponent::openMode;

	m_FileChooser->launchAsync(folderChooserFlags, [this](const FileChooser& chooser) {
		File seletedFile(chooser.getResult());
	});
}
