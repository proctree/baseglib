#ifndef __GTEXTURE_H__
#define __GTEXTURE_H__
#include<iostream>
#include<iomanip>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<string>
#include<vector>
#include<limits>
#include<baseglib.h>

class gTexture{
	private:
		SDL_Texture* mTex;
		SDL_Renderer** mRPointer;
		int mW;
		int mH;
	public:
		gTexture();
		gTexture(SDL_Renderer** gRPointer);
		gTexture(SDL_Renderer** gRPointer,std::string gFilename);
		gTexture(TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded=false,SDL_Color gBG=SDL_Color());
		gTexture(SDL_Renderer** gRPointer,TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded=false,SDL_Color gBG=SDL_Color());
		~gTexture();
		void setRenderer(SDL_Renderer** gRPointer);
		bool destroyTex();
		bool loadTex(std::string gFilename);
		bool TTFloadTex(TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded=false,SDL_Color gBG=SDL_Color());
		int getW();
		int getH();
		bool render(int rX,int rY,SDL_Rect* rClip=NULL,double angle=0.0,SDL_Point* center=NULL,double resW=1.0,double resH=1.0);
};

#endif