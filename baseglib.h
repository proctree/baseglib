#ifndef __BASEGLIB_H__
#define __BASEGLIB_H__
#include<iostream>
#include<iomanip>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<string>
#include<vector>
#include<limits>
#include<gTexture.h>
#include<deltaTime.h>

extern int glib_Error;
#define glib_SDLINITERROR 1
#define glib_IMGINITERROR 2
#define glib_TTFINITERROR 3
#define glib_WINDOWINITERROR 4
#define glib_RENDERERINITERROR 5
#define glib_NOSETRENDERER 6
#define glib_TEMPSURFERROR 7
#define glib_TEMPTEXERROR 8
#define glib_NOSETTEX 9

bool glib_Init(Uint32 SDLflags=SDL_INIT_EVERYTHING,Uint32 IMGflags=IMG_INIT_PNG|IMG_INIT_JPG);
void glib_ResetError();
bool glib_InitWindow(SDL_Window* &gWindow,SDL_Renderer* &gRenderer,const std::string &wTitle="SDL Window",int wH=800,int wW=600,int wX=SDL_WINDOWPOS_UNDEFINED,int wY=SDL_WINDOWPOS_UNDEFINED,const Uint32 &wFlags=SDL_WINDOW_SHOWN);
void glib_Quit();

#endif