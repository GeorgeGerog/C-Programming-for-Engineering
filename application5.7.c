/* Application 5_7 calculates the min force to move a block for differnt angles*/

#include <stdio.h>
#include <math.h>
#define Pi 3.14

/* takes weight and friction coefficient and returns force */

double force (double weight, double fr_coef,int t,int b);
void input (double *w, double *f);
void print_output(double force1, int t,int b);

int main ()
{
	double weight,fr_coef,force1;
	int b,t;
	
	input(&weight,&fr_coef);
	printf("The weight is W=%.2lf N and the friction coef is %.2lf\n", weight,fr_coef);
	
	for (t=0;t<=80;t+=10)
	{
		for(b=0;b<=80;b+=10)
		{
		
			if((t+b)<=90)
			{
	
	force1= force (weight,fr_coef,t,b);
	print_output(force1,t,b);
    		}/*end if*/
    	}/*end inside for*/
	}/*end out side for*/
		return 0;
	
}

void input (double *w, double *f)
{
	printf("please type weight anf friction coef\n");
	scanf("%lf %lf",&*w,&*f);
}

double force (double weight, double fr_coef,int t,int b)
{
	double force2;
	force2=(weight*sin(b*Pi/180.)+fr_coef*weight*cos(b*Pi/180.))/(fr_coef*sin(t*Pi/180.)+cos(t*Pi/180.));
	return force2;
}

void print_output(double force1, int t, int b)
{
	printf("for theta =%d degrees and b=%d the min force is %.2lf N\n",t,b,force1);
}
