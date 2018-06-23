/* Application 5_7 calculates the min force to move a block for differnt angles*/

#include <stdio.h>
#include <math.h>
#define Pi 3.14

/* takes weight and friction coefficient and returns force */

double force (double weight, double fr_coef,int t,int b);

void print_output(double force1, int t,int b,double fr_coef);

int main ()
{
	double weight=30000,fr_coef,force1;
	int b,t;
	

	printf("The weight is W=%.2lf N \n", weight);
	
	for (fr_coef=0.1;fr_coef<=0.4;fr_coef+=0.1)
	{
	
	for (t=0;t<=80;t+=10)
	{
		for(b=0;b<=80;b+=10)
		{
		
			if((t+b)<=90)
			{
	
	force1= force (weight,fr_coef,t,b);
	print_output(force1,t,b,fr_coef);
    		}/*end if*/
    	}/*end inside for*/
	}/*end out side for*/
}
		return 0;
	
}



double force (double weight, double fr_coef,int t,int b)
{
	double force2;
	force2=(weight*sin(b*Pi/180.)+fr_coef*weight*cos(b*Pi/180.))/(fr_coef*sin(t*Pi/180.)+cos(t*Pi/180.));
	return force2;
}

void print_output(double force1, int t, int b,double fr_coef)
{
	printf("for friction coef %.2lf theta =%d degrees and b=%d the min force is %.2lf N\n",fr_coef,t,b,force1);
}
