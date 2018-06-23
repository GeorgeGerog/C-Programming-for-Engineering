/* Eyklideios Algorithm to find Greatest common divisor GCD*/

int gcd(int x,int y);

void input (int *g, int *h);

void print_out(int k, int l, int result);

void main (void)
{
	int a,b, maxcd;
	
	input(&a,&b);
	maxcd=gcd(a,b);


 	print_out(a,b,maxcd);
 
	
}

void input(int *g,int *h)
{
	printf("Enter the A B integers\n");
	scanf("%d %d",&*g,&*h);
}

void print_out(int k, int l, int result)
{
	if(result==0) 
	{
		printf("the %d and the %d have no common divisor\n");
	}
   else printf("The Greatest common divisor of %d and %d is %d\n",k,l,result);
}

int gcd (int x, int y)
{
	int ypol;
	
	do 
	{
	
	    if (x%y==0)
		 {
		return y;
		 break;
		 }
	    else 
	    {
	    	ypol=x%y;
	    	x=y;
	    	y=ypol;
		}
	} while (x%y!=0);
	return y;
}
