#ifndef _AUDIO_H_
#define _AUDIO_H_
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>

class Audio
{
public:
	Audio();
	~Audio();

	void loadAudio(const std::string & file, int volume);
	void playSingle();
	void playLoop();
	void setVolume(int vol);
	void changeVolume(int vol);
	void stopPlay();
	void mute();
	void unmute();
	int getVolume();
	bool muted = false;
	sf::Sound m_sound;

private:

	sf::SoundBuffer s;
	int m_volume;
};

#endif;