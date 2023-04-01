#include "MainComponent.h"
#include "src/OBJParser.h"

//==============================================================================
MainComponent::MainComponent()
    :m_Parser{ Util::OBJParser{} }
{
    setSize (600, 50);
	m_ASCIIToBinaryBtn.setButtonText("ASCII to binary obj");
	m_BinaryToASCIIBtn.setButtonText("Binary to ASCII obj");
    addAndMakeVisible(m_ASCIIToBinaryBtn);
    addAndMakeVisible(m_BinaryToASCIIBtn);

    m_ASCIIToBinaryBtn.onClick = [this]()
    {
        SelectFile(false);
    };

    m_BinaryToASCIIBtn.onClick = [this]()
	{
		SelectFile(true);
	};
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
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    m_ASCIIToBinaryBtn.setBounds(10, 10, 200, 30);
    m_BinaryToASCIIBtn.setBounds(310, 10, 200, 30);
}

void MainComponent::SelectFile(bool isReversed)
{
    const std::string fileExtension = isReversed? "*.bobj": "*.obj";

	m_FileChooser = std::make_unique<FileChooser>(
        "Please select the file to load...",
		File::getSpecialLocation(File::userHomeDirectory),
		fileExtension
		);

	auto folderChooserFlags = FileBrowserComponent::openMode;


	m_FileChooser->launchAsync(folderChooserFlags, [this, isReversed](const FileChooser& chooser) {
		File selectedFile(chooser.getResult());

        if (isReversed)
        {
            ConvertBinaryToASCII(selectedFile);
        }
        else
        {
            ConvertASCIIToBinary(selectedFile);
        }
	});
}

void MainComponent::ConvertASCIIToBinary(File& file)
{
    m_Parser.ReadTextOBJFile(file.getFullPathName().toStdString());

    std::string locationToSave = file.getFullPathName().dropLastCharacters(4).toStdString();

    m_Parser.WriteToBinary(locationToSave + ".bobj");
}

void MainComponent::ConvertBinaryToASCII(File& file)
{
	m_Parser.ReadBinaryOBJFile(file.getFullPathName().toStdString());

	std::string locationToSave = file.getFullPathName().dropLastCharacters(5).toStdString();

	m_Parser.WriteToText(locationToSave + ".obj");
}
