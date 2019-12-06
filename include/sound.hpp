#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>

#ifndef SOUND_H
#define SOUND_H

using namespace std;

class Sound {
	public :
		Sound();
		~Sound();
		int Load();
		void close();
		void Launch(int l);
	private :
		string SMusic;
		Mix_Music *gMusic;
		string Ssound1;
		Mix_Chunk *gsound1;
		string Ssound2;
		Mix_Chunk *gsound2;
		string Ssound3;
		Mix_Chunk *gsound3;
		string Ssound4;
		Mix_Chunk *gsound4;
		string Ssound5;
		Mix_Chunk *gsound5;
};

#endif
