/*application 5_13 calculates  velocity and direction after plastic collision for different angles and masses*/

#include <stdio.h>
#include <math.h>
#define Pi 3.14

void collision (double m1,double m2, double v1,double v2,double t,double *v3,double *b);
void print_out(double m1,double m2,double v2,double t, double v3, double b);

int main()
{
	double m1,m2,v1, v2,t,v3,b; /* t =theta initial angle in degrees*/ 

	v1=30.;  /*m/s*/
	
	for(m1=1000.;m1<=3000.;m1+=1000)
	{
		for(m2=2000.;m2<=6000.;m2+=2000)
			{
				for(t=10;t<=90;t+=10)
				{
				
					for (v2=20;v2<=80;v2+=10)
						{
							collision(m1,m2,v1,v2,t,&v3,&b);
							print_out(m1,m2,v2,t,v3,b);
						}
				}
			}
	}
	return 0;
}

void collision (double m1,double m2, double v1,double v2,double t,double *v3,double *b)
{
	double b_rad;
	*v3=sqrt(pow(m1*v1,2)+pow(m2*v2,2)+2*m1*v1*m2*v2*cos(t*Pi/180.))/(m1+m2);
	b_rad=atan(m2*v2*sin(t*Pi/180.)/(m1*v1+m2*v2*cos(t*Pi/180.)));
	*b=b_rad*180./Pi;
}

void print_out(double m1,double m2,double v2,double t, double v3, double b)
{
	
	printf("for m1=%.2lf kg and m2=%.2lf kg and t=%.2lf degrees v2=%.2lf m/s\n" 
			"v3=%.2lf m/s and b=%.2lf degrees\n",m1,m2,t,v2,v3,b);
}

