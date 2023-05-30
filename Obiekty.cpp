#include "Obiekty.h"

Object::Object(SDL_Renderer* rend, const char* FilePath) : renderer(NULL), texture(NULL) {
	renderer = rend;
	texture = IMG_LoadTexture(renderer, FilePath);
	dst.x = 100;
	dst.y = 564;
	dst.w = 64;
	dst.h = 64;
	src.x = 0;
	src.y = 0;
	src.w = 64;
	src.h = 64;
}

SDL_Texture* Object::getTex() {
	return texture;
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

void Object::setDst(SDL_Rect newDst) {
	dst = newDst;
}

void Object::render() {
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

Object::~Object() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
}