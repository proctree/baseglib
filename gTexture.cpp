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

gTexture::gTexture(){
	mRPointer=NULL;
	mTex=NULL;
	mW=0;
	mH=0;
}
gTexture::gTexture(SDL_Renderer** gRPointer){
	mRPointer=gRPointer;
	mTex=NULL;
	mW=0;
	mH=0;
}
gTexture::gTexture(TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded,SDL_Color gBG){
	mRPointer=NULL;
	mTex=NULL;
	mW=0;
	mH=0;
	TTFloadTex(gFont,gText,gColor,gShaded,gBG);
}
gTexture::gTexture(SDL_Renderer** gRPointer,TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded,SDL_Color gBG){
	mRPointer=gRPointer;
	mTex=NULL;
	mW=0;
	mH=0;
	TTFloadTex(gFont,gText,gColor,gShaded,gBG);
}
gTexture::gTexture(SDL_Renderer** gRPointer,std::string gFilename){
	mRPointer=gRPointer;
	mTex=NULL;
	mW=0;
	mH=0;
	loadTex(gFilename);
}
gTexture::~gTexture(){
	destroyTex();
}
void gTexture::setRenderer(SDL_Renderer** gRPointer){
	mRPointer=gRPointer;
}
bool gTexture::destroyTex(){
	if(mTex!=NULL){
		SDL_DestroyTexture(mTex);
		mTex=NULL;
		return 0;
	}
	return 1;
}
bool gTexture::loadTex(std::string gFilename){
	SDL_Surface* tempSurf=IMG_Load(gFilename.c_str());
	if(tempSurf==NULL){
		glib_Error=glib_TEMPSURFERROR;
		return 1;
	}
	if(mRPointer==NULL){
		glib_Error=glib_NOSETRENDERER;
		return 1;
	}
	SDL_Texture* tempTexture=SDL_CreateTextureFromSurface(*mRPointer,tempSurf);
	mW=tempSurf->w;
	mH=tempSurf->h;
	SDL_FreeSurface(tempSurf);
	if(tempTexture==NULL){
		glib_Error=glib_TEMPTEXERROR;
		return 1;
	}
	if(mTex!=NULL){
		SDL_DestroyTexture(mTex);
	}
	mTex=tempTexture;
	return 0;
}
bool gTexture::TTFloadTex(TTF_Font* gFont,std::string gText,SDL_Color gColor,bool gShaded,SDL_Color gBG){
	SDL_Surface* tempSurf=NULL;
	if(gShaded==false){
		tempSurf=TTF_RenderText_Solid(gFont,gText.c_str(),gColor);
	}
	else{
		tempSurf=TTF_RenderText_Shaded(gFont,gText.c_str(),gColor,gBG);
	}
	if(tempSurf==NULL){
		glib_Error=glib_TEMPSURFERROR;
		return 1;
	}
	if(mRPointer==NULL){
		glib_Error=glib_NOSETRENDERER;
		return 1;
	}
	SDL_Texture* tempTexture=SDL_CreateTextureFromSurface(*mRPointer,tempSurf);
	mW=tempSurf->w;
	mH=tempSurf->h;
	SDL_FreeSurface(tempSurf);
	if(tempTexture==NULL){
		glib_Error=glib_TEMPTEXERROR;
		return 1;
	}
	if(mTex!=NULL){
		SDL_DestroyTexture(mTex);
	}
	mTex=tempTexture;
	return 0;
}
int gTexture::getW(){
	return mW;
}
int gTexture::getH(){
	return mH;
}
bool gTexture::render(int rX,int rY,SDL_Rect* rClip,double rAngle,SDL_Point* rCenter,double resW,double resH){
	SDL_Rect renderRect={rX,rY,mW,mH};
	if(rClip!=NULL){
		renderRect.w=rClip->w;
		renderRect.h=rClip->h;
	}
	renderRect.w*=resW;
	renderRect.h*=resH;
	if(mTex==NULL){
		glib_Error=glib_NOSETTEX;
		return 1;
	}
	if(mRPointer==NULL){
		glib_Error=glib_NOSETRENDERER;
		return 1;
	}
	return (SDL_RenderCopyEx(*mRPointer,mTex,rClip,&renderRect,rAngle,rCenter,SDL_FLIP_NONE))!=0;
}