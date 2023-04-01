#pragma once

#include <JuceHeader.h>
#include "src/OBJParser.h"

#include <functional>


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)

    void SelectFile(bool isReversed);
    void ConvertASCIIToBinary(File& file);
    void ConvertBinaryToASCII(File& file);

	juce::TextButton m_ASCIIToBinaryBtn{};
	juce::TextButton m_BinaryToASCIIBtn{};

    Util::OBJParser m_Parser;
    std::unique_ptr<FileChooser> m_FileChooser{};
};
