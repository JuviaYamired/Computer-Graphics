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
	friction();
}

void ClassPlayer::friction()
{
	velocity[0] -= 0.09;
	if (velocity[0] <= 0){
		velocity[0] = 0;
	}

	if (velocity[0] > 0.5){
		velocity[0] = 0.5;
	}

	if (lastDirection){
		position[0] = position[0] + velocity[0] * 1;
	}
	else{
		position[0] = position[0] + (-velocity[0]) * 1;
	}
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

void ClassPlayer::walk()
{
	velocity[0] += acceleration;
	if(velocity[0] > 0.5){
		velocity[0] = 0.5;
	}

	if (direction){
		position[0] = position[0] + velocity[0];
	}
	else{
		position[0] = position[0] + (-velocity[0]);
	}
}

void ClassPlayer::jump(){
	//position[0] = position[0] + velocity[1];
	position[1] = position[1] + velocity[1];
	
	//position[1] = sqrt(2 * gravity * 4);
}