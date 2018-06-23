/*application 5_9 calculates forces at the edge of o stick*/
#include <stdio.h>
#include <math.h>

/*takes lenght and weight*/
void input (double *l,double *w);
/*take lenght and weight and return fa,fb*/
void force (double l,double w,double x,int f, double *fa,double *fb);
void print_out(double fa,double fb,double x,int f);

int main()
{
	double fa,fb,l,w,x;
	int f;/* kN=1000N*/
	
	input(&l,&w);
	
	for(f=100;f<=500;f+=100)
	{
		for(x=0.;x<=l;x+=0.25*l)
		{
		
	
	force(l,w,x,f,&fa,&fb);
	print_out(fa,fb,x,f);
		}
	}
	return 0;
}

void input (double *l,double *w)
{
	printf("please type the lenght and the weight of the rod\n");
	scanf("%lf %lf",&*l,&*w);
}
void force (double l,double w,double x,int f, double *fa,double *fb)
{
	*fb=(w/2.)+f*(1-x/l);
	*fa=f+w-(*fb);
}

void print_out(double fa,double fb,double x,int f)
{
	printf("for f=%dkN and x=%.2lfm fa=%.2lfkN fb=%.2lfkN \n",f,x,fa,fb);
}

