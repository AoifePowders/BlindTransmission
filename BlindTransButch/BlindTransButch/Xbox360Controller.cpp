#include "XBOX360CONTROLLER.h"

Xbox360Controller::Xbox360Controller()
{
	connect();
}

Xbox360Controller::~Xbox360Controller()
{
}

void Xbox360Controller::update()
{
	if (isConnected())
	{
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 0))
		{
			m_currentState.A = true;
		}
		else
		{
			m_currentState.A = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 1))
		{
			m_currentState.B = true;
		}
		else
		{
			m_currentState.B = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 2))
		{
			m_currentState.X = true;
		}
		else
		{
			m_currentState.X = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 3))
		{
			m_currentState.Y = true;
		}
		else
		{
			m_currentState.Y = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 4))
		{
			m_currentState.LB = true;
		}
		else
		{
			m_currentState.LB = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 5))
		{
			m_currentState.RB = true;
		}
		else
		{
			m_currentState.RB = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 6))
		{
			m_currentState.Back = true;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 7))
		{
			m_currentState.Start = true;
		}
		else
		{
			m_currentState.Start = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 8))
		{
			m_currentState.LeftThumbStickClick = true;
		}
		else
		{
			m_currentState.LeftThumbStickClick = false;
		}
		if (sf::Joystick::isButtonPressed(sf_Joystick_index, 9))
		{
			m_currentState.RightThumbStickClick = true;
		}
		else
		{
			m_currentState.RightThumbStickClick = false;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::X) > joystickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::X) < -joystickThreshold)
		{
			m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::X);
		}
		else
		{
			m_currentState.LeftThumbStick.x = 0;
		}
		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Y) > joystickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Y) < -joystickThreshold)
		{
			m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Y);
		}
		else
		{
			m_currentState.LeftThumbStick.y = 0;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::U) > joystickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::U) < -joystickThreshold)
		{
			m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::U);
		}
		else
		{
			m_currentState.RightThumbStick.x = 0;
		}
		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::R) > joystickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::R) < -joystickThreshold)
		{
			m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::R);
		}
		else
		{
			m_currentState.RightThumbStick.y = 0;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovY) > 0 + dPadThreshold)
		{
			m_currentState.DpadUp = true;
		}
		else
		{
			m_currentState.DpadUp = false;
		}
		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovY) < 0 - dPadThreshold)
		{
			m_currentState.DpadDown = true;
		}
		else
		{
			m_currentState.DpadDown = false;
		}
		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovX) < 0 - dPadThreshold)
		{
			m_currentState.DpadLeft = true;
		}
		else
		{
			m_currentState.DpadLeft = false;
		}
		if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovX) > 0 + dPadThreshold)
		{
			m_currentState.DpadRight = true;
		}
		else
		{
			m_currentState.DpadRight = false;
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -5.f)
		{
			m_currentState.Rtrigger = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Z);
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) > 15.f)
		{
			m_currentState.Ltrigger = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Z);
		}
	}

}

bool Xbox360Controller::isConnected()
{
	if (sf::Joystick::isConnected(sf_Joystick_index))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Xbox360Controller::connect()
{
	if (sf::Joystick::isConnected(0))
	{
		sf_Joystick_index = 0;
		return true;
	}
	else
	{
		return false;
	}
}
