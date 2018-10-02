#include "ClassPlayer.h"
#include <stdio.h>
#include <iostream>
#include <thread>

ClassPlayer::ClassPlayer(){
    position[0] = 0;
    position[1] = 0;
	velocity[0] = 0;
	velocity[1] = 0;
	actions[1] = false;
}

void ClassPlayer::draw(){
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D,"wolf.png");
	glTranslatef(position[0], position[1], 0);
    displayEnix(0, 0, 2);
	//	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//friction();
}

void ClassPlayer::friction()
{	
	if(direction == RIGHT){
		velocity[0]-= 10;
		if(velocity[0] <= 0)
			velocity[0] = 0;
	}
	if( direction == LEFT){
		velocity[0]+= 10;
		if(velocity[0] >= 0)
			velocity[0] = 0;
	}
	velocity[1]+= GRAVITY;
}

void ClassPlayer::executeAction(){
	//if doing nothing
	if(actions[0]){

	}
	//If walking
	else if(actions[1]){
		walk();
	}
	else if(actions[2]){
		jump();
	}
	//If jumping
	else if(actions[3]){	

	}
	//If sliding
	else if(actions[4]){

	}
	//If Dodging
	else if(actions[5]){

	}
	//If Attacking
	else if(actions[6]){

	}
}


void ClassPlayer::move(){
	friction();
	position[0]+= velocity[0] * DTTIME;
	position[1]+= velocity[1] * DTTIME + 1/2 * GRAVITY * DTTIME;
	if(position[1] <= 0)
		position[1] = 0;	
	std::cout<< velocity[0] <<std::endl;
}

void ClassPlayer::walk()
{
	if(direction == RIGHT){
		velocity[0]+= acceleration;
		if(velocity[0] > maxVelocity)
			velocity[0] = maxVelocity;
	}
	if( direction == LEFT){
		velocity[0]-= acceleration;
		if(velocity[0] < -maxVelocity)
			velocity[0] = -maxVelocity;
	}
}

void ClassPlayer::jump(){
	//velocity[0]+= 100 * cos(degToRad(45));
	velocity[1]+= 100;
}