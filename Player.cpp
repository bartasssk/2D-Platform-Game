#include "Player.h"
#include "Collider.h"
#include "Enemy.h"
#include <string>


const float PLAYER_SPEED = 8.0f;
const float JUMP_VEL = 30.0f;


Player::Player(SDL_Renderer* rend, const char* FilePathLeft, const char* FilePathRight) : Character(rend, "textures/rycerzykRight.png"), currentEvent(nullptr), sword(rend, "textures/mieczyk1.png") {
	SDL_Surface* tempSurfLeft = IMG_Load(FilePathLeft);
	leftTexture = SDL_CreateTextureFromSurface(getRend(), tempSurfLeft);
	SDL_FreeSurface(tempSurfLeft);
	SDL_Surface* tempSurfRight = IMG_Load(FilePathRight);
	rightTexture = SDL_CreateTextureFromSurface(getRend(), tempSurfRight);
	SDL_FreeSurface(tempSurfRight);
	SDL_Surface* swordSurf1 = IMG_Load("textures/mieczyk1.png");
	swordRight = SDL_CreateTextureFromSurface(getRend(), swordSurf1);
	SDL_FreeSurface(swordSurf1);
	SDL_Surface* swordSurf2 = IMG_Load("textures/mieczyk2.png");
	swordLeft = SDL_CreateTextureFromSurface(getRend(), swordSurf2);
	SDL_FreeSurface(swordSurf2);
	currentSide = Side::RIGHT;
	currentState = State::STANDING;
	movingDelay = 8;
	standingDelay = 15;
	swordDelay = 2;
	currentFrame = 0;
	ifnulled = false;
	hit = false;
	ifdead = true;
	SDL_Rect SwordDst = sword.getDst(), SwordSrc = sword.getSrc();

	SwordDst.x = 0;
	SwordDst.y = 0;
	SwordDst.h = 64;
	SwordDst.w = 64;

	SwordSrc.w = 32;
	SwordSrc.h = 32;
	sword.setDst(SwordDst);
	sword.setSrc(SwordSrc);
	setHP(5);
}

void Player::move() {
	if (currentEvent->type == SDL_KEYDOWN and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			currentSide = Side::LEFT;
			if (CanIMoveLeft == true) {
				velX -= PLAYER_SPEED;
				if (velX == 0) {
					ifnulled = false;
				}
			}
			break;
		}
		case SDLK_RIGHT: {
			currentSide = Side::RIGHT;
			if (CanIMoveRight == true) {
				velX += PLAYER_SPEED;
				if (velX == 0) {
					ifnulled = false;
				}
			}
			break;
		}
		case SDLK_UP: {
			if (grounded == true) {
				setCanIMove(true, true);
				velY += JUMP_VEL;
				setGroundState(false);
			}
			break;
		}
		case SDLK_SPACE: {
			currentState = State::ATTACKING;
			break;
		}
		}
		
	}
	else if (currentEvent->type == SDL_KEYUP and currentEvent->key.repeat == 0) {
		switch (currentEvent->key.keysym.sym) {
		case SDLK_LEFT: {
			if (velX < 0 or ifnulled == false) {
				velX += PLAYER_SPEED;
			}
			break;
		}
		case SDLK_RIGHT: {
			if (velX > 0 or ifnulled == false) {
				velX -= PLAYER_SPEED;
			}
			break;
		}
		case SDLK_SPACE: {
			currentState = State::STANDING;
			hit = false;
			break;
		}
		}
	}
	SDL_Rect newDst = getDst();
	newDst.x += velX;
	setDst(newDst);
}

void Player::attack(Enemy *enemy, Player* player) {
	SDL_Rect swordDst = sword.getDst();
	SDL_Rect PlayerDst = getDst();
	SDL_Rect EnemyDst = enemy->getDst();


	if (currentState == State::ATTACKING and currentSide == Side::LEFT) {
  		sword.setTex(swordLeft);
		swordDst.x = PlayerDst.x - 48;
		swordDst.y = PlayerDst.y;
		sword.setDst(swordDst);

		if (hit == false) {
			if (SDL_HasIntersection(&EnemyDst, &swordDst)) {
				hit = true;
				enemy->setHP(enemy->getHP() - 1);
			}
		}
	}
	else if(currentState == State::ATTACKING and currentSide == Side::RIGHT){
		sword.setTex(swordRight);
		swordDst.x = PlayerDst.x + 48;
		swordDst.y = PlayerDst.y;
		sword.setDst(swordDst);
		if (hit == false) {
			if (SDL_HasIntersection(&EnemyDst, &swordDst)) {
				hit = true;
 				enemy->setHP(enemy->getHP() - 1);
				enemy->getHP();
			}
		}
	}
	else {
		sword.setTex(nullptr);
		swordDst.x = 0;
		swordDst.y = 0;
		sword.setDst(swordDst);
	} 
}

void Player::animate() {
	currentFrame++;
	
		if (currentSide == Side::RIGHT) {
			setTex(rightTexture);
		}
		else if (currentSide == Side::LEFT) {
			setTex(leftTexture);
		}

	if (currentState != State::ATTACKING) {

		if (velX != 0 and grounded == true) {
			currentState = State::MOVING;
		}
		else if (velX == 0 and grounded == true) {
			currentState = State::STANDING;
		}
		else if (velY != 0) {
			currentState = State::JUMPING;
		}
	}

	switch (currentState) {
	case State::STANDING: {
		if (currentFrame / standingDelay >= 2) {
			currentFrame = 0;
		}
		SDL_Rect src = getSrc();
		src.x = currentFrame / standingDelay * 64;
		setSrc(src);
		break;
	}
	case State::MOVING: {
		if (currentFrame / movingDelay >=6) {
			currentFrame = 2;
		}
		SDL_Rect src = getSrc();
		src.x = currentFrame / movingDelay * 64;
		setSrc(src);
		break;
	}
	case State::JUMPING: {
		SDL_Rect src = getSrc();
		src.x = 7 * 64;
		setSrc(src);
		break;
	}
	case State::ATTACKING:{
		if (currentFrame / swordDelay >= 6) {
			currentFrame = 0;
		}
		else if (hit == true) {
			currentFrame = 10;
		}

		SDL_Rect src = getSrc();
		SDL_Rect swordSrc = sword.getSrc();
		src.x = 8 * 64;
		setSrc(src);

		if (hit == false) {
			swordSrc.x = currentFrame / swordDelay * 32;
			sword.setSrc(swordSrc);
		}
		else if (hit == true and currentFrame / swordDelay <= 5) {
			swordSrc.x = currentFrame / swordDelay * 32;
			sword.setSrc(swordSrc);
		}

		break;
	}
	default:
		break;
	}
}

void Player::die() {
	const int SCREEN_HEGHT = 720;

	if (HP <= 0) {
		ifdead = true;
	}

	if (getDst().y > 720) {
		ifdead = true;
		setHP(0);
	}
}

void Player::setIfNulled(bool result) {
	ifnulled = result;
}

void Player::renderSword() {
	sword.render();
}

void Player::setIfDead(bool newState) {
	ifdead = newState;
}

Player::~Player() {
	sword.clean();
}

