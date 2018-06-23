/*application 5_21 Q=C*i*A */

#include <stdio.h>
#include <math.h>
#define MAX 50

void read_data (double *i, double *A,double *C);


int main()
{
	double i,A,Q,C;
	
	read_data(&i,&A,&C);
	
	Q=C*i*A;
	printf("the Q=%.2lf \n",Q);
	return 0;
	
}

void read_data (double *i, double *A,double *C)
{
	int j,k,l;
	FILE *input;
	double space[MAX],C1[MAX],sum_space=0.,sum_c=0.;
	input=fopen("C:\\Users\\user\\Desktop\\dec c-c++\\data521.txt","r");
	fscanf(input,"%lf",&*i);
	j=0;
	while(fscanf(input,"%lf %lf",&space[j],&C1[j])!=EOF) j++;
	

	for(k=0;k<=j-1;k++)
	{
		sum_space+=space[k];
	}
	*A=sum_space;

		for(l=0;l<=j-1;l++)
	{
		sum_c+=C1[l]*space[l]/(*A);
	}
	*C=sum_c;
	fclose(input);
	
	
	
}
