#include<iostream>
#include<iomanip>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<string>
#include<vector>
#include<limits>
#include<baseglib.h>
#include<gTexture.h>

int glib_Error;

bool glib_Init(Uint32 SDLflags,Uint32 IMGflags){
	glib_Error=0;
	if(SDL_Init(SDLflags)){
		glib_Error=glib_SDLINITERROR;
		return 1;
	}
	if(!(IMGflags & IMG_Init(IMGflags))){
		glib_Error=glib_IMGINITERROR;
		return 1;
	}
	if(TTF_Init()){
		glib_Error=glib_TTFINITERROR;
		return 1;
	}
	return 0;
}

inline void glib_ResetError(){
	glib_Error=0;
}

bool glib_InitWindow(SDL_Window* &gWindow,SDL_Renderer* &gRenderer,const std::string &wTitle,int wH,int wW,int wX,int wY,const Uint32 &wFlags){
	gWindow=SDL_CreateWindow(wTitle.c_str(),wX,wY,wH,wW,wFlags);
	if(gWindow==NULL){
		glib_Error=glib_WINDOWINITERROR;
		return 1;
	}
	gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
	if(gRenderer==NULL){
		glib_Error=glib_RENDERERINITERROR;
		return 1;
	}
	SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
	return 0;
}

void glib_Quit(){
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	std::cout<<"Press enter to continue.."<<std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
