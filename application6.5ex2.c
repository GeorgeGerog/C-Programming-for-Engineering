/*application 6_5 ex2*/
#include<stdio.h>
#define SIZE1 30
#define SIZE2 60

void input(int data[SIZE1][SIZE2]);
void print_input(int data[SIZE1][SIZE2]);
void compress_file(int data[SIZE1][SIZE2]);
void expand_file();

int main (void)
{
int x[SIZE1][SIZE2];

input(x);
print_input(x);
compress_file(x);
expand_file();

return 0;           
}

/**********************************************
**		READ INPUT FILE
**********************************************/
void input(int data[SIZE1][SIZE2])
{
	int i,j;
	FILE *infile;
	infile = fopen ("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\INPUT.DAT","r");
	
	for (i=0; i<=SIZE1-1; i++)
		{
		for (j=0; j<=SIZE2-1; j++)
			{
			fscanf(infile,"%1d",&data[i][j]);
			}
		}
fclose(infile);
}
/**********************************************
**		PRINT INPUT FILE
**********************************************/
void print_input(int data[SIZE1][SIZE2])
{
	int i,j;
	for (i=0; i<=SIZE1-1; i++)
		{
		for (j=0; j<=SIZE2-1; j++)
			{
			printf("%1d",data[i][j]);
			}
		printf("\n");
		}
}

/***********************************************
**			COMPRESS FILE
***********************************************/

void compress_file(int data[SIZE1][SIZE2])
{
	int i,j,count;
	FILE *outfile1;
	outfile1 = fopen("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\output1.txt","w+");
	
	count = 0;
	printf("\n\n\n");
	for (j=0; j<=SIZE1-1; j++)
		{
		for (i=0; i<=SIZE2-1; i++)
			{
			count++;
			if (i == SIZE2-1 || data[j][i] != data[j][i+1])
				{
				fprintf(outfile1,"%d ",count);
				printf("%d ",count);
				count = 0;
				}
			 }
		 fprintf(outfile1,"\n");
		 printf("\n");
		 }
		 fclose(outfile1);
	 
}

/***********************************************
**  EXPAND FILE
***********************************************/
void expand_file()
{
	int i,j,a,count,sum;
	FILE *outfile2;
	outfile2 = fopen("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\output1.txt","r");
	
	for (j=1; j<=SIZE1; j++)
		{
		a=0;
		sum=0;
		do
			{
			fscanf(outfile2,"%d",&count);
			for (i=1; i<=count; i++) printf ("%1d",a);
			a=!a;
			sum+=count;
			} while (sum<SIZE2);
		printf("\n");
		}
	
}

