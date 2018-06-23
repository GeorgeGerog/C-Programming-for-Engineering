/* Program for application 6_3 */  
    
#include <stdio.h>
#define MAX_NUM_ROWS 20
#define MAX_NUM_COLS 20

void input(double matr[MAX_NUM_ROWS][MAX_NUM_COLS],double vec[MAX_NUM_COLS],int *num_rows, int *num_cols,int *icountrows);
void matrxvec(double matr[MAX_NUM_ROWS][MAX_NUM_COLS],double vec[MAX_NUM_COLS],double result[MAX_NUM_ROWS],int num_rows, int num_cols);

int main (void)
{
	double a[MAX_NUM_ROWS][MAX_NUM_COLS], x[MAX_NUM_COLS];
	double b[MAX_NUM_ROWS];
	int i, j, num_rows, num_cols,icountrows;
	
	input(a,x,&num_rows,&num_cols,&icountrows);

	printf("icountrows=%d\n",icountrows);
	
	if(icountrows!=num_cols) 
	{
		printf("error dimesions of matrix dont match \n"
			   "matrix is %dx%d and vector %dx1\n",num_rows,num_cols,icountrows);
	}
	else
	{
	matrxvec(a,x,b,num_rows,num_cols);
	}
		return 0;
}

void input(double matr[MAX_NUM_ROWS][MAX_NUM_COLS],double vec[MAX_NUM_COLS],int *num_rows,int *num_cols,int *icountrows)
{
	int i, j,count=0;

	FILE *infile;
	
	infile=fopen("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\MATVECT.DAT","rt");
	fscanf(infile,"%d %d",&*num_rows,&*num_cols);

	for (i=0; i<*num_rows; i++)
		{
		for (j=0; j<*num_cols; j++)
			{
			fscanf (infile,"%lf",&matr[i][j]);
			}
		fscanf (infile,"%lf",&vec[i]);
		count++;
		}
		
	while(fscanf (infile,"%lf",&vec[i])!=EOF) 
	{
	
	count++;
	}
	*icountrows=count;
}

void matrxvec(double matr[MAX_NUM_ROWS][MAX_NUM_COLS],double vec[MAX_NUM_COLS],double result[MAX_NUM_ROWS],int num_rows, int num_cols)
{
int i,j;

	printf("\nb vector");

	for (i=0; i<num_rows; i++)
		{
		result[i]=0;
		for (j=0; j<num_cols; j++)
			{
			result[i] += matr[i][j]*vec[j];
			}
		printf("\n%lf", result[i]);
		}
}
