#ifndef __DELTATIME_H__
#define __DELTATIME_H__
#include<iostream>
#include<iomanip>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<string>
#include<vector>
#include<limits>
#include<gTexture.h>
#include<baseglib.h>

class gTimer{		
	private:
		Uint32 mCTicks;
		Uint32 mLTicks;
	public:
		gTimer();
		gTimer(Uint32 gCustomTicks);
		void start();
		void setTicks(Uint32 gCustomTicks);
		Uint32 getDeltaTime();
		void capFPS(int gFPS);
};

#endif