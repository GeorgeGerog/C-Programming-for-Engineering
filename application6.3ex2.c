/* Program for application 6_3 */  
    
#include <stdio.h>
#define MAX_NUM_ROWS 20
#define MAX_NUM_COLS 20

int main (void)
{
	double a[MAX_NUM_ROWS][MAX_NUM_COLS], x[MAX_NUM_COLS];
	double b[MAX_NUM_ROWS];
	int i, j, num_rows, num_cols,icountrows=0;
	FILE *infile;

	infile=fopen("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\MATVECT.DAT","rt");
	fscanf(infile,"%d %d",&num_rows,&num_cols);

	for (i=0; i<num_rows; i++)
		{
		for (j=0; j<num_cols; j++)
			{
			fscanf (infile,"%lf",&a[i][j]);
			}
		fscanf (infile,"%lf",&x[i]);
		icountrows++;
		}
		
	while(fscanf (infile,"%lf",&x[i])!=EOF) 
	{
	
	icountrows++;
	}
	printf("icountrows=%d\n",icountrows);
	
	if(icountrows!=num_cols) 
	{
		printf("error dimesions of matrix dont match \n"
			   "matrix is %dx%d and vector %dx1\n",num_rows,num_cols,icountrows);
	}
	else
	{
	printf("\nb vector");

	for (i=0; i<num_rows; i++)
		{
		b[i]=0;
		for (j=0; j<num_cols; j++)
			{
			b[i] += a[i][j]*x[j];
			}
		printf("\n%lf", b[i]);
		}
	}
		return 0;
}

