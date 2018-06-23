/* programm to calculate the possible moves of a rock in chessbord*/
#include <stdio.h>
#include <math.h>
int check_point(int i,int j);

int main(void)
{
int i,j,icount;
for(j=1;j<=8;j++)
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
	int k,m, icountx=0,icounty=0;
	for(k=1;k<=8;k++) if(k!=i) icountx++;
	for(m=1;m<=8;m++) if(m!=j) icounty++;
	
	return (icountx+icounty);
}
