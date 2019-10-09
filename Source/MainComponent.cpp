/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(checkTheTimeButton);
    checkTheTimeButton.setButtonText("Check the time...");
    checkTheTimeButton.addListener(this);
    
    addAndMakeVisible(timeLabel);
    timeLabel.setColour(Label::backgroundColourId, Colours::black);
    timeLabel.setColour(Label::textColourId, Colours::white);
    timeLabel.setJustificationType(Justification::centred);
    
    //timeOfLastClick = Time::getMillisecondCounter();
    latestTime = Time::getCurrentTime();
    
    setSize (600, 110);
}

MainComponent::~MainComponent()
{
    checkTheTimeButton.removeListener(this);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    checkTheTimeButton.setBounds (10, 10, getWidth() - 20, 40);
    timeLabel.setBounds (10, 60, getWidth() - 20, 40);
}

void MainComponent::buttonClicked (Button* button)
{
    if (button == &checkTheTimeButton)
    {
        //Display time
            //auto currentTime = Time::getCurrentTime();
            //auto includeDate = true;
            //auto includeTime = true;
            //auto includeSeconds = true;
            //auto use24HourClock = false;
            //auto currentTimeString = currentTime.toString(includeDate, includeTime, includeSeconds, use24HourClock);
            //timeLabel.setText(currentTimeString, dontSendNotification);
        
        //My solution to find ms time between clicks
            //auto currentTime = Time::getMillisecondCounter();
            //timeLabel.setText("Time since last click: " + (String)(currentTime - timeOfLastClick) + " ms", dontSendNotification);
            //timeOfLastClick = currentTime;
        
        //Juce solution to find ms time between clicks
            auto currentTime = Time::getCurrentTime();
            RelativeTime timeDifference (currentTime - latestTime);
            auto timeDifferenceString = String (timeDifference.inMilliseconds()) + " milliseconds";
            timeLabel.setText (timeDifferenceString, dontSendNotification);
            latestTime = currentTime;
    }
}
