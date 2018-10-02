#include <iostream>
#include <math.h>

using namespace std;

float random(float a, float b)
{
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

class vector3d
{
	public:
		float x;
		float y;
		float z;


	public:
		vector3d();
		void mult(vector3d a);	
		void div(vector3d a);	
		void sub(vector3d a);
		void add(vector3d a);
		void normalize();		
};
vector3d::vector3d(){
	x=0.0;
	y=0.0;
	z=0.0;
}
void vector3d::mult(vector3d a){
	x*=a.x;
	y*=a.y;
	z*=a.z;
}
void vector3d::div(float n){
	x/=n;
	y/=n;
	z/=n;
}
void  vector3d::sub(vector3d a){
	x-=a.x;
	y-=a.y;
	z-=a.z;
}
void  vector3d::add(vector3d a){
	x+=a.x;
	y+=a.y;
	z+=a.z;
}
void vector3d::normalize(){
	float m=(float)sqrt(x*x + y*y + z*z);
	if (m>0)
	{
		div(m);
	}
}