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
#include<deltaTime.h>

gTimer::gTimer(){
	mLTicks=mCTicks=SDL_GetTicks();
}

gTimer::gTimer(Uint32 gCustomTicks){
	mLTicks=mCTicks=SDL_GetTicks();
	setTicks(gCustomTicks);
}

void gTimer::start(){
	mLTicks=mCTicks;
	mCTicks=SDL_GetTicks();
}

void gTimer::setTicks(Uint32 gCustomTicks){
	mLTicks=mCTicks;
	mCTicks=gCustomTicks;
}

Uint32 gTimer::getDeltaTime(){
	return SDL_GetTicks()-mLTicks;
}

void gTimer::capFPS(int mFPS){
	float framerate=1000/mFPS;
	int elaps=this->getDeltaTime();
	if(elaps<framerate){
		SDL_Delay(framerate-elaps);
	}
}