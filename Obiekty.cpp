#include "Obiekty.h"

Object::Object(SDL_Renderer* rend, const char* FilePath) : renderer(rend), texture(NULL) {
	SDL_Surface* tempSurf = IMG_Load(FilePath);
	texture = SDL_CreateTextureFromSurface(renderer,tempSurf);
	SDL_FreeSurface(tempSurf);
	dst.x = 100;
	dst.y = 564;
	dst.w = 64;
	dst.h = 64;
	src.x = 0;
	src.y = 0;
	src.w = 64;
	src.h = 64;
}

SDL_Rect Object::getDst() {
	return dst;
}

SDL_Rect Object::getSrc() {
	return src;
}

SDL_Renderer* Object::getRend() {
	return renderer;
}

SDL_Texture* Object::getTex() {
	return texture;
}

void Object::setDst(SDL_Rect newDst) {
	dst = newDst;
}

void Object::setSrc(SDL_Rect newSrc) {
	src = newSrc;
}

void Object::setTex(SDL_Texture* newTexture) {
	texture = newTexture;
}

void Object::render() {
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Object::clean() {
	SDL_DestroyTexture(texture);
}

Object::~Object() {
}