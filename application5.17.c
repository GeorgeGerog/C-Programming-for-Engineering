/*application 5_17 calculates the  electrical intensity in parallel circuit*/

#include <stdio.h>
#include <math.h>

void intensity(double v,double r1,double r2,double r3, double *i1,double *i2,double *i3);
void print_out( double i1,double i2,double i3);

int main(void)
{
	double I1,I2,I3,V;
	int i;
	double R1[3]={10.,20.,30.};
	double R2[3]={40.,60.,80.};
	double R3[3]={100.,120.,130.};
	V=30.;
	
	for(i=0;i<3;i++)
	{
		intensity(V,R1[i],R2[i],R3[i],&I1,&I2,&I3);
		print_out(I1,I2,I3);
	}
	return 0;
	
}

void intensity(double v,double r1,double r2,double r3, double *i1,double *i2,double *i3)
{
	*i1=v/r1;
	*i2=v/r2;
	*i3=v/r3;
}

void print_out( double i1,double i2,double i3)
{
	printf(" I1=%.2lf A  I2=%.2lf A  I3=%.2lf A\n",i1,i2,i3);
}

