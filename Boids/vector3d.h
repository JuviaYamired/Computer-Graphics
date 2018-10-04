#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <math.h>

using namespace std;

class vector3d
{
	public:
		float x;
		float y;
		float z;

		vector3d(){
			x=0.0;
			y=0.0;
			z=0.0;	
		}
		vector3d(float a,float b,float c){
			x=a;
			y=b;
			z=c;
		}
		void mult(float a){
			x*=a;
			y*=a;
			z*=a;
		}	
		void div(float n){
			x/=n;
			y/=n;
			z/=n;
		}	
		void sub(vector3d a){
			x-=a.x;
			y-=a.y;
			z-=a.z;
		}
		void add(vector3d a){
			x+=a.x;
			y+=a.y;
			z+=a.z;
		}
		void normalize(){
			float m=(float)sqrt(x*x + y*y + z*z);
			if (m>0)
			{
				div(m);
			}
		}	//vector normalizado;
		void print(){
			cout<<" ("<<x<<","<<y<<","<<z<<") "<<endl;
		}
			
};

#endif
