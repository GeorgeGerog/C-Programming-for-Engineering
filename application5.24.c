/*application 5_24 p=v*i (watt) */

#include <stdio.h>
#include <math.h>


double power(double v2,double i2);
void print_out(double v3,double i3, double p3);

int main (void)
{
	double p,v,i,o;
	int j;		
	FILE *input;
	
	input=fopen("C:\\Users\\user\\Desktop\\dec c-c++\\data524.txt","r");
	
	while(fscanf(input,"%lf %lf",&v,&i)!=EOF)
	{
		p=power(v,i);
		print_out(v,i,p);
	}
	
	return 0;
}

double power(double v2,double i2)
{
	return(v2*i2);
}

void print_out(double v3,double i3, double p3)
{
	printf("the v=%.2lf volt i=%.2lf Ampere p=%.2lf watt\n",v3,i3,p3);
}
