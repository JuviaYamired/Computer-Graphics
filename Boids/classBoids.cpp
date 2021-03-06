#include "classBoids.h"

classBoids::classBoids(){
    boidsQuantity = 10;    
}

classBoids::classBoids(int mBoidsQuantity){
    boidsQuantity = mBoidsQuantity;
}

void classBoids::initialize(){
    for(int i=0; i < boidsQuantity; ++i){
        Boids.push_back( new classEntity( vector3d(randomFloat(-20, 20), randomFloat(-20, 20), randomFloat(-20, 20) ) ) );
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
    vector3d v1,v2,v3;
    for(int i=0; i < boidsQuantity; ++i){
        //v1=rule1();
          v2=rule2(i);
          v3=rule3(i);


        //vector1 = rule1();
        //vector2 = rule2();
        //vector3 = rule3();
          //b.velocity = b.velocity + v1 + v2 + v3
        //Boids[i]->velocity.add(v1);
        Boids[i]->velocity.add(v2);//faltaria vector v1 / += 0;//vector1 + vector2 + vector3;
        Boids[i]->velocity.add(v3);
        //b.position = b.position + b.velocity
        Boids[i]->position.add(Boids[i]->velocity);// += velocity 
    }
    
}

vector3d classBoids::rule1(int pos){
    vector3d centerOfMass(0, 0, 0);
    for(int i = 0; i < Boids.size(); ++i){
        if(i != pos)
            centerOfMass.add( Boids[i]->position );
    } 
    centerOfMass.div(Boids.size() - 1);
    centerOfMass.sub(Boids[pos]->position);
    centerOfMass.div(100);
    return centerOfMass;
}
