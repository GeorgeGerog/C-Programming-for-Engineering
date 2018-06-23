/*application 5_12 calculates  velocity and direction after plastic collision*/

#include <stdio.h>
#include <math.h>
#define Pi 3.14

void collision (double m1,double m2, double v1,double v2,double *v3,double *b);
void print_out(double v2, double v3, double b);

int main()
{
	double m1,m2,v1, v2,v3,b;
	m1=1000.; /* in Kg*/
	m2=3000.;
	v1=30.;  /*m/s*/
	
	printf("the mass is m1=%.2lf kg m2=%.2lf kg and velocity v1=%.2lf m/s \n",m1,m2,v1);
	
	for (v2=20;v2<=80;v2+=10)
	{
		collision(m1,m2,v1,v2,&v3,&b);
		print_out(v2,v3,b);
	}
	return 0;
}

void collision (double m1,double m2, double v1,double v2,double *v3,double *b)
{
	double b_rad;
	*v3=sqrt(pow(m1*v1,2)+pow(m2*v2,2))/(m1+m2);
	b_rad=atan(m2*v2/(m1*v1));
	*b=b_rad*180./Pi;
}

void print_out(double v2, double v3, double b)
{
	printf("for v2=%.2lf m/s v3=%.2lf m/s and b=%.2lf degrees\n",v2,v3,b);
}

