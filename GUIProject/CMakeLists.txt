set(SOURCES
    Main.cpp
    MainComponent.h
    MainComponent.cpp
)

juce_add_gui_app(GUIProject
    PRODUCT_NAME "My Amzing Dog walking App"
    VERSION ${PROJECT_VERSION}
    COMPANY_NAME "KoenSoft"
    DOCUMENT_EXTENSIONS "myext"
    DOCUMENT_NAMES "My Document"
    DOCUMENT_DESCRIPTIONS "My Document Description"
)

juce_generate_juce_header(GUIProject)

target_sources(GUIProject PRIVATE ${SOURCES})

target_include_directories(GUIProject PUBLIC
    # self root reference
    #"${CMAKE_CURRENT_SOURCE_DIR}"

    # I do know how to do these?
    "${CommonCodeIncludeDir}"
)

# Link against the JUCE module
target_link_libraries(GUIProject
    PRIVATE
        # GuiAppData            # If we'd created a binary data target, we'd link to it here
        juce::juce_gui_extra
    PUBLIC
        CommonCode
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
