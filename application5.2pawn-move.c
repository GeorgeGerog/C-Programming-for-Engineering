/* programm to calculate the possible moves of a pawn in chessbord*/
#include <stdio.h>
int check_point(int i,int j);

int main(void)
{
int i,j,icount;
for(j=2;j<=8;j++)
    {
    	for(i=1;i<=8;i++)
    	{
    		icount=check_point(i,j);
    		printf("%5d",icount);
		}
		printf("\n");
	}
	return 0;	
}

int check_point(int i, int j)
{
	int icount;
	icount=(j==2)?2:1;
	return icount;
}

