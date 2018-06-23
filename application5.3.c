/* chapter 5 application 3 computing earthquake magnitude*/
#include <stdio.h>
#include <math.h>

int earthquake(double E, double L,double *M);

void input(double *E,double *L);

void print_out(int i,double M);

void main (void)
{
	double E,L,M;
	int i;
	input(&E,&L);
	i=earthquake(E,L,&M);
	print_out(i,M);
}

void input(double *E,double *L)
{
	printf("please enter energy and lenght of sxisma\n");
	scanf("%lf %lf",&*E,&*L);
}

/***********************************************
** Energy is in erg ,1 gigajoule =10^16 erg
** 
    Magnitude 3 = 2 gigajoules
    Magnitude 4 = 63 gigajoules
    Magnitude 5 = 2,000 gigajoules
    Magnitude 6 = 63,000 gigajoules
    Magnitude 7 = 2,000,000 gigajoules **/

int earthquake(double E, double L,double *M)
{
	double m1,m2;
	
	m1=(log10(E)-11.8)/1.5;
	m2=(log10(L)+5.77)/1.02;
	
	printf("m1= %.2lf m2=%0.2lf\n",m1,m2);
	if(fabs(m1-m2)<=0.2*((m1+m2)/2.0))
	{
	*M=(m1+m2)/2.0;
	return 1;	
	}
	else return 0;
}
void print_out(int i,double M)
{
	if(i==0)
	{
		printf("the numbers are incompatible\n");
	}
	else 
	{
		printf("the magnidute of the earthquake is %.2lf\n",M);
	}
}
