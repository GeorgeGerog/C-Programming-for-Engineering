/*application 5_18 calculates the  electrical intensity for 5 resitors in parallel circuit*/

#include <stdio.h>
#include <math.h>

void intensity(double v,double r1,double r2,double r3,double r4,double r5, double *i1,double *i2,double *i3,double *i4,double *i5);
void print_out( double i1,double i2,double i3,double i4,double i5);

int main(void)
{
	double I1,I2,I3,I4,I5,V;
	int i;
	double R1[3]={10.,20.,30.};
	double R2[3]={40.,60.,80.};
	double R3[3]={100.,120.,130.};
	double R4[3]={50.,70.,90.};
	double R5[3]={140.,160.,180.};
	
	V=30.;
	
	for(i=0;i<3;i++)
	{
		intensity(V,R1[i],R2[i],R3[i],R4[i],R5[i],&I1,&I2,&I3,&I4,&I5);
		print_out(I1,I2,I3,I4,I5);
	}
	return 0;
	
}

void intensity(double v,double r1,double r2,double r3,double r4,double r5, double *i1,double *i2,double *i3,double *i4,double *i5)
{
	*i1=v/r1;
	*i2=v/r2;
	*i3=v/r3;
	*i4=v/r4;
	*i5=v/r5;
}

void print_out( double i1,double i2,double i3,double i4,double i5)
{
	printf(" I1=%.2lf A  I2=%.2lf A  I3=%.2lf A I4=%.2lf A I5=%.2lf A \n",i1,i2,i3,i4,i5);
}

