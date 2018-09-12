#include "player.h"
#include <stdio.h>
#include <iostream>

player::player(){
    position[0]=0;
    position[1]=0;
}

void player::draw(){
	glPushMatrix();
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D,"wolf.png");
	glTranslatef(position[0], position[1], 0);
    displayEnix(0, 0, 2);
	//	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	friction();
}

void  player::friction(){
	velocity-= 0.05;
	if(velocity < 0){
		velocity = 0;
	}
	if(velocity > 1){
		velocity = 1;
	}
}

void player::walk(bool direction){
	if (velocity > 2)
	{
		velocity = 2;
	}

	velocity+= acceleration;

	if (direction == RIGHT)
	{
		position[0] = position[0] + velocity * 1;
	}
	if (direction == LEFT)
	{
		position[0] =  position[0] + (-velocity) * 1;
	}

	std::cout<<"velocity "<< velocity<<std::endl;
	std::cout<<"pos0 "<<position[0]<<"pos1 "<<position[1]<<std::endl;
}