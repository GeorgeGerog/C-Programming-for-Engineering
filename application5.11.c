/*application 5_111 calculates forces  to move an auto*/
#include <stdio.h>
#include <math.h>
#define Pi 3.14159265

void forces (int t1,int b1,double *f1,double *f2);
void print_out(int t,int b,double fa,double fb);

int main()
{
	int t,b;
	double fa,fb;
	
	for(t=10;t<=80;t+=10)
	{
		for(b=10;b<=80;b+=10)
		{
			if((t+b)<=140)
			{
				forces(t,b,&fa,&fb);
				print_out(t,b,fa,fb);
			}
		}
	}
	return 0;
	
}
void forces (int t1,int b1,double *f1,double *f2)
{
	*f2=3000.0/(sin(b1*Pi/180)/(tan(t1*Pi/180))+cos(t1*Pi/180));
	*f1=(*f2)*sin(b1*Pi/180)/sin(t1*Pi/180);
}


void print_out(int t,int b,double fa,double fb)
{
	printf("for t=%d deg and b=%d the fa=%.2lf and fb=%.2lf\n",t,b,fa,fb);
}

