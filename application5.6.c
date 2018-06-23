/* Application 5_6 calculates the min force to move a block for differnt angles*/

#include <stdio.h>
#include <math.h>
#define Pi 3.14

/* takes weight and friction coefficient and returns force */

double force (double weight, double fr_coef,int i);
void input (double *w, double *f);
void print_output(double force1, int i);

int main ()
{
	double weight,fr_coef,force1;
	int i;
	
	input(&weight,&fr_coef);
	printf("The weight is W=%.2lf N and the friction coef is %.2lf\n", weight,fr_coef);
	
	for (i=5;i<=80;i+=5)
	{
	if(i==5 ||i%10==0)
	{
	
	force1= force (weight,fr_coef,i);
	print_output(force1,i);
    }
    }
	return 0;
	
}

void input (double *w, double *f)
{
	printf("please type weight anf friction coef\n");
	scanf("%lf %lf",&*w,&*f);
}

double force (double weight, double fr_coef,int i)
{
	double force2;
	force2=(weight*fr_coef)/(fr_coef*sin(i*Pi/180.)+cos(i*Pi/180.));
	return force2;
}

void print_output(double force1, int i)
{
	printf("for %d degrees the min force is %.2lf N\n",i,force1);
}
