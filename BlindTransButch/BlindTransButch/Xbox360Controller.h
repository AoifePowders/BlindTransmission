#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// data to store the current state of the controller
/// </summary>
struct GamePadState
{
	bool A{ false };
	bool B{ false };
	bool X{ false };
	bool Y{ false };
	bool LB{ false };
	bool RB{ false };
	bool LeftThumbStickClick{ false };
	bool RightThumbStickClick{ false };
	bool DpadUp{ false };
	bool DpadDown{ false };
	bool DpadLeft{ false };
	bool DpadRight{ false };
	bool Start{ false };
	bool Back{ false };
	bool Xbox{ false };
	float Rtrigger;
	float Ltrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

/// <summary>
/// Xbox controller class to query current state of the controller
/// to mimic the controller states like XNA
/// </summary>
class Xbox360Controller
{
private:
	//deadzone for the dpad
	const int dPadThreshold = 50;
	//deadzone for joysticks	
	const int joystickThreshold = 10;

public:
	//index count for multiple controllers if connected
	int sf_Joystick_index{ 0 };
	//the current state of all the buttons
	GamePadState m_currentState;
	//the previous state to use to check for the moment a button is pressed
	GamePadState m_previousState;

	Xbox360Controller();
	~Xbox360Controller();
	void Xbox360Controller::update();
	bool isConnected();
	bool connect();
};
#endif //!XBOX360CONTROLLER