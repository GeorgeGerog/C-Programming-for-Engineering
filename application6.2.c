/***************************chapter 6 application  ex_3********************
Date :8/1/2017
Programmer : George
***************************************************************************/

#include <stdio.h>
#define MAX_SIZE 100
void get_data(int x[MAX_SIZE],int *i);
void display_data(int x[MAX_SIZE],int i);
void display_results (int data[MAX_SIZE],int i);

int main()
{
	int data [MAX_SIZE],i,freq[MAX_SIZE];
	get_data(data,&i);
	display_data(data,i);
	display_results(data,i);	   
		   
	return 0;
}

void get_data(int x[MAX_SIZE],int *i)
{
	int count=0;
	FILE *input;
	input=fopen("C:\\Users\\user\\Desktop\\programming etc\\about c\\dec c-c++\\EX6_1.txt","r");
	
	/*************read  data*************/
		
	count=0;
	
	while(fscanf(input,"%d",&x[count])!=EOF) 
	{
	
	count++;
	}
	
	*i=count;
	
}

void display_data(int x[MAX_SIZE],int i)
{
int k;
	printf("------------------------------------\n"
		   "no. Day	           Million gallon\n"
		   "------------------------------------\n");
for(k=0;k<i;k++)
	{
	printf("%d\t\t\t%d\n",k,x[k]);
	 }	   
}

void display_results (int data[MAX_SIZE],int i)
{
	int freq[MAX_SIZE],j;
		/************* set freq array to zero***********/
	for(j=0;j<i;j++) freq[j]=0;
	
	for(j=0;j<i;j++)
	{
		if(data[j]>=81 && data[j]<=90) freq[0]++;
		else if(data[j]>=91 && data[j]<=100) freq[1]++;
		else if(data[j]>=101 && data[j]<=110) freq[2]++;
		else if(data[j]>=111 && data[j]<=120) freq[3]++;
		else if(data[j]>=121 && data[j]<=130) freq[4]++;
		else if(data[j]>=131 && data[j]<=140) freq[5]++;
		else if(data[j]>=141 && data[j]<=150) freq[6]++;
	}
	printf("------------------------------------\n"
		   "Sewage per day	      frequency\n"
		   "------------------------------------\n\n");
	printf("81-90\t\t\t%d\n"
		   "91-100\t\t\t%d\n"
		   "101-110\t\t\t%d\n"
		   "111-120\t\t\t%d\n"
		   "121-130\t\t\t%d\n"
		   "131-140\t\t\t%d\n"
		   "141-150\t\t\t%d\n",freq[0],freq[1],freq[2],freq[3],freq[4],freq[5],freq[6]);	   
		   
}

