#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
/**
 * @brief Class responsible for objects texture, rendering, etc.
*/
class Object {
private:
	/**
	 * @brief Texture of the object.
	*/
	SDL_Texture* texture;
	/**
	 * @brief SDL_Renderer.
	*/
	SDL_Renderer* renderer;
	/**
	 * @brief Destination to which the object is rendered.
	*/
	SDL_Rect dst;
	/**
	 * @brief Part of the picture that it renders.
	*/
	SDL_Rect src;
public:
	/**
	 * @brief Constructor.
	 * @param rend SDL_Renderer.
	 * @param FilePath Path of the picture that takes to create texture.
	*/
	Object(SDL_Renderer* rend, const char* FilePath);
	/**
	 * @brief Default constructor.
	*/
	Object() = default;
	/**
	 * @brief Saves to renderer to render this object.
	*/
	void render();
	/**
	 * @brief Setter for destination.
	*/
	void setDst(SDL_Rect newDst);
	/**
	 * @brief Setter for source.
	*/
	void setSrc(SDL_Rect newSrc);
	/**
	 * @brief Setter for texture.
	*/
	void setTex(SDL_Texture* newTexture);
	/**
	 * @brief Cleans the object.
	*/
	void clean();
	/**
	 * @brief Getter for renderer.
	*/
	SDL_Renderer* getRend();
	/**
	 * @brief Getter for destination of the texture.
	*/
	SDL_Rect getDst();
	/**
	 * @brief Getter for source of the texture.
	*/
	SDL_Rect getSrc();
	/**
	 * @brief Getter for texture.
	*/
	SDL_Texture* getTex();
	/**
	 * @brief Destructor.
	*/
	~Object();
};