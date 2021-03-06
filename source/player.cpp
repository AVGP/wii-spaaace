#include "player.h"

Player::Player() {
	respawningCountdown = 0;
}

void Player::update(u32 buttonsHeld, u32 buttonsPressed, wsp::Sprite **enemies) {
	if(buttonsHeld & WPAD_BUTTON_RIGHT && !CollidesWith(bounds.top.GetRectangle())) {
		Move(0, -5);
	} else if(buttonsHeld & WPAD_BUTTON_LEFT && !CollidesWith(bounds.bottom.GetRectangle())) {
		Move(0, 5);
	}

	if(buttonsHeld & WPAD_BUTTON_UP && !CollidesWith(bounds.left.GetRectangle())) {
		Move(-2, 0);
	} else if(buttonsHeld & WPAD_BUTTON_DOWN && !CollidesWith(bounds.right.GetRectangle())) {
		Move(2, 0);
	}

	if(buttonsPressed & WPAD_BUTTON_2 && respawningCountdown == 0) {
		int i;
		for(i=0;i<numOwnShots;i++) {
			if(ownShots[i]->isFired() == false) {
				ownShots[i]->fire(GetX() + GetWidth(), GetY() + (GetHeight()/2) - 10, 5);
				break;
			}
		}
	}
	
	if(respawningCountdown == 0) {
		int i=0;
		for(i=0;i<NUM_ALIENS;i++) {
			if(CollidesWith(enemies[i])) {
				startRespawn();
				break;
			}
		}

		for(i=0;i<numEnemyShots;i++) {
			if(enemyShots[i]->isFired() == false) continue;
		
			if(CollidesWith(enemyShots[i]) && respawningCountdown == 0) {
				startRespawn();
				break;
			}
		}
	} else {
		if(--respawningCountdown == 0) stopRespawn();
	}
	
}

void Player::setShots(Shot **shots, unsigned int numberOfShots, bool isOwn) {
	if(isOwn) {
		ownShots = shots;
		numOwnShots = numberOfShots;
	} else {
		enemyShots = shots;
		numEnemyShots = numberOfShots;		
	}
}

void Player::startRespawn() {
	if(respawningCountdown > 0) return;
	lifes--;
	SetTransparency(127);
	respawningCountdown = RESPAWN_TIME;
}

void Player::stopRespawn() {
	respawningCountdown = 0;
	SetTransparency(255);
}
