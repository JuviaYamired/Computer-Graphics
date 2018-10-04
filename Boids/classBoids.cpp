#include "classBoids.h"

classBoids::classBoids(){
    boidsQuantity = 10;    
}

classBoids::classBoids(int mBoidsQuantity){
    boidsQuantity = mBoidsQuantity;
}

void classBoids::initialize(){
    for(int i=0; i < boidsQuantity; ++i){
        vector3d t(randome(1,3),randome(1,3),randome(1,3));
        Boids.push_back( new classEntity(t));
    }
}

void classBoids::drawBoids(){
	 /*for(int i=0; i < boidsQuantity; ++i){
        Boids[i]->draw();}	*/


}
vector3d classBoids::rule2(int j){ //Separation
    float sep=25.0f;
    float d=0;
    vector3d  C(0,0,0);

    for (int i = 0; i < Boids.size(); ++i)
    {   
        if(i!=j)
        {
            d=dist(Boids[i]->position,Boids[j]->position);
            if(abs(d)<sep)
            {   vector3d tmp=Boids[i]->position;
                tmp.sub(Boids[j]->position);
                C.sub(tmp);
            }
        }

    }
    return C;
}
vector3d classBoids::rule3(int j){ //Separation
    vector3d  pvj(0,0,0);

    for (int i = 0; i < Boids.size(); ++i)
    {   
        if(i!=j)
        {
            Boids[i]->velocity.print();
            pvj.add(Boids[i]->velocity);
        }
    }
    pvj.div(Boids.size()-1);
    pvj.sub(Boids[j]->velocity);
    pvj.div(8);
    return pvj;
}
void classBoids::update(){
   /* float vector1[3], vector2[3], vector3[3];
    for(int i=0; i < boidsQuantity; ++i){
        //vector1 = rule1();
        //vector2 = rule2();
        //vector3 = rule3();
        Boids[i]->velocity += 0;//vector1 + vector2 + vector3;
        Boids[i].position += velocity 
    }
    */

}


