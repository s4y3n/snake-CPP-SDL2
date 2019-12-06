#include "sound.hpp"

Sound::Sound()
{
	SMusic = "sounds/theme-music.wav";
	gMusic = NULL;
	//bump.mp3";
	Ssound1 = "sounds/coin.mp3";
	gsound1 = NULL;
	Ssound2 = "sounds/dead.wav";
	gsound2 = NULL;
	Ssound3 = "sounds/jump.wav";
	gsound3 = NULL;
	Ssound4 = "sounds/ping.mp3";
	gsound4 = NULL;
	Ssound5 = "sounds/smash.mp3";
	gsound5 = NULL;	
}


Sound::~Sound()
{


}

int Sound::Load()
{
	int gotIt = 0;
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Failed to init Audio" << endl;
		gotIt = 1;
	}
	else 
	{
		gMusic = Mix_LoadMUS(SMusic.c_str());
		if(gMusic == NULL)
		{
			cout << "Failed to open music file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
		gsound1 = Mix_LoadWAV(Ssound1.c_str());
		if(gsound1 == NULL)
		{
			cout << "Failed to open sound1 file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
		gsound2 = Mix_LoadWAV(Ssound2.c_str());
		if(gsound2 == NULL)
		{
			cout << "Failed to open sound2 file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
		gsound3 = Mix_LoadWAV(Ssound3.c_str());
		if(gsound3 == NULL)
		{
			cout << "Failed to open sound3 file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
		gsound4 = Mix_LoadWAV(Ssound4.c_str());
		if(gsound4 == NULL)
		{
			cout << "Failed to open sound4 file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
		gsound5 = Mix_LoadWAV(Ssound5.c_str());
		if(gsound5 == NULL)
		{
			cout << "Failed to open sound5 file : " << Mix_GetError() << endl;
			gotIt = 1;
		}
	}
	return gotIt;
}

void Sound::close()
{
	Mix_FreeChunk(gsound1);
	Mix_FreeChunk(gsound2);
	Mix_FreeChunk(gsound3);
	Mix_FreeChunk(gsound4);
	Mix_FreeChunk(gsound5);
	Mix_FreeMusic(gMusic);

	Mix_Quit();
}

void Sound::Launch(int l)
{
	switch(l)
	{
		case 1 :
			Mix_PlayChannel(-1, gsound1, 0);
			break;
		case 2 :
			Mix_PlayChannel(-1, gsound2, 0);
			break;
		case 3 :
			Mix_PlayChannel(-1, gsound3, 0);
			break;
		case 4 :
			Mix_PlayChannel(-1, gsound4, 0);
			break;
		case 5 :
			Mix_PlayChannel(-1, gsound5, 0);
			break;
		case 6 :
			if(Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(gMusic, -1);
			}
			else
			{
				if(Mix_PausedMusic() == 1 ) // Music paused 
				{
					Mix_ResumeMusic();

				}else
				{
					Mix_PauseMusic();
				}
			}
			break;		
	}

}

