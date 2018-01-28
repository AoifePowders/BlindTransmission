#ifndef _AUDIO_H_
#define _AUDIO_H_
#include <SFML\Audio.hpp>

#include <string>
#include <iostream>

class Audio
{
public:
	Audio();
	Audio(const std::string & file, int volume, std::string t);
	~Audio();

	void loadAudio(const std::string & file, int volume, std::string t);
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
	std::string getTag();

	void SetListener(sf::Vector3f pos, int vol);
	void setSoundPos(sf::Vector3f pos);

private:

	sf::SoundBuffer s;
	int m_volume;
	std::string m_tag;
};

#endif;