/*application 5_19 calculates provision of a fluid dV/dt=Q=k*i*A */
#include <stdio.h>
#include <math.h>
#define Pi 3.14

void flow_rate(double D,double L,double k, double H);

int main()
{
	double D=10.,L=200.,H=50.,k=0.1;
	
	flow_rate(D,L,k,H);
	
	return 0;
	
}
void flow_rate(double D,double L,double k, double H)
{
	double Q,i,A;
	
	i=H/L;
	A=Pi*pow(D/2,2);
	Q=k*i*A;
	
	printf("the dV/dt=%.2lf cm^3/sec\n",Q);
}
