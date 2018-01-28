#include "Audio.h"



Audio::Audio()
{
}
Audio::Audio(const std::string & file, int volume, std::string t)
{
	std::cout << "Loading " << t << std::endl;
	m_tag = t;
	s.loadFromFile(file);
	m_sound.setBuffer(s);
	m_sound.setVolume(volume);
}

Audio::~Audio()
{
}
//Adds the sound from file to the buffer.
void Audio::loadAudio(const std::string & file, int volume, std::string t)
{
	std::cout << "Loading";
	m_tag = t;
	s.loadFromFile(file);
	m_sound.setBuffer(s);
	m_sound.setVolume(volume);
}
//Plays Audio once
void Audio::playSingle()
{
	m_sound.play();
}
//Play audio and loops it when done
void Audio::playLoop()
{
	m_sound.setLoop(true);
	m_sound.play();
}
//Change the volume to a value
void Audio::setVolume(int vol)
{
	m_volume = vol;
	m_sound.setVolume(vol);
}
//increases/decreases to current volume
void Audio::changeVolume(int vol)
{
	m_volume += vol;
	m_sound.setVolume(m_volume);
}
//Stops audio i.e. looping audio
void Audio::stopPlay()
{
	m_sound.stop();
}
//Returns current volume
int Audio::getVolume()
{
	return m_volume;
}
//mutes the sound
void Audio::mute()
{
	if (!muted)
	{
		m_sound.setVolume(0);
		muted = true;
	}
}
//unmutes the sound
void Audio::unmute()
{
	if (muted)
	{
		m_sound.setVolume(m_volume);
		muted = false;
	}
}
//identify the sound
std::string Audio::getTag()
{
	return m_tag;
}
//Sets the listener of the scene -> player position
void Audio::SetListener(sf::Vector3f pos, int vol)
{
	sf::Listener::setPosition(pos);
	sf::Listener::setGlobalVolume(vol);
}
//sets the sound position - > (x, 0, y)
void Audio::setSoundPos(sf::Vector3f pos)
{
	m_sound.setPosition(pos);
}