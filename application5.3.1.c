/********************************************
** A cross (B cross C)
********************************************/

#include <stdio.h>
#include <math.h>

void cross_product  (double g1, double g2, double g3,\ 
		              double h1, double h2, double h3,\ 
		              double *k1, double *k2, double *k3); 

void AxBxC   (double g1, double g2, double g3,\ 
			   double h1, double h2, double h3,\ 
			   double k1, double k2, double k3,\
			   double *l1, double *l2, double *l3);  
		              
 
void read_input (double *g1, double *g2, double *g3,\ 
		 double *h1, double *h2, double *h3,\ 
		 double *k1, double *k2, double *k3); 
 
void print_output (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
 		double c1, double c2, double c3,\ 
 		double d1, double d2, double d3 ); 
/************************************************************************************ 
 **	FUNCTION main 
 **		VARIABLES 
 **			a1, a2, a3 = COMPONENTS OF VECTOR A 
 **			b1, b2, b3 = COMPONENTS OF VECTOR B 
 **			c1, c2, c3 = COMPONENTS OF VECTOR C 
**			d1, d2, d3 = COMPONETS OF  VECTOR D=Ax(BXC) 
*************************************************************************************/  		
 		
 void main (void) 
 { 
	double a1, a2, a3, b1, b2, b3, c1, c2, c3, d1,d2,d3; 
	read_input (&a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3); 
	AxBxC(a1, a2, a3, b1, b2, b3, c1, c2, c3, &d1,&d2,&d3);
	
	
	print_output (a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3); 
} 

/******************************************************************* 
**	FUNCTION cross_product 
**   CALCULATES THE CROSS PRODUCT OF TWO VECTORS G AND H 
 **		VARIABLES - INPUT 
 **			g1, g2, g3 = COMPONENTS OF VECTOR G 
 **			h1, h2, h3 = COMPONENTS OF VECTOR H 
 **		VARIABLES - OUTPUT 
 **			*k1, *k2, *k3 = COMPONENTS OF VECTOR THAT IS 
 **			                           THE CROSS PRODUCT 
 *********************************************************************/ 
  
 void   cross_product (double g1, double g2, double g3,\ 
 		      double h1, double h2, double h3, \ 
 		      double *k1, double *k2, double *k3) 
 { 
	*k1 = g2*h3 - g3*h2; 
	*k2 = -(g1*h3 - g3*h1); 
	*k3 = g1*h2 - g2*h1; 
 } 
 /******************************************************************* 
**	FUNCTION AxBxC
**   CALCULATES THE DOUBLE CROSS PRODUCT OF 3 VECTORS GxHxK 
 **		VARIABLES - INPUT 
 **			g1, g2, g3 = COMPONENTS OF VECTOR G 
 **			h1, h2, h3 = COMPONENTS OF VECTOR H 
          	k1, k2, k3 = COMPONENTS OF VECTOR K
 **		VARIABLES - OUTPUT 
 **			*l1, *l2, *l3 = COMPONENTS OF VECTOR THAT IS 
 **			                           THE  DOUBLE CROSS PRODUCT 
 *********************************************************************/ 
 
 void AxBxC (double g1, double g2, double g3,\ 
			   double h1, double h2, double h3,\ 
			   double k1, double k2, double k3,\
			   double *l1, double *l2, double *l3)
{
	double f1,f2,f3;
	
	cross_product (h1,  h2, h3, k1,k2, k3, &f1,&f2,&f3);
					
	cross_product ( g1,  g2,  g3, f1, f2, f3, &*l1,&*l2,&*l3);
					 
 		      
}

/******************************************************************* 
**	FUNCTION read_input 
**     READS INPUT DATA FROM KEYBOARD 
**		VARIABLES - OUTPUT 
**			*g1, *g2, *g3 = COMPONENTS OF VECTOR G 
**			*h1, *h2, *h3 = COMPONENTS OF VECTOR H 
**			*k1, *k2, *k3 = COMPONENTS OF VECTOR K 
 *********************************************************************/ 
  
void read_input (double *g1, double *g2, double *g3,\ 
		 double *h1, double *h2, double *h3,\ 
		 double *k1, double *k2, double *k3) 
{ 
	printf ("Enter vector A (a1 a2 a3): \n"); 
	scanf ("%lf %lf %lf", &*g1, &*g2, &*g3); 
	printf ("Enter vector B (b1 b2 b3): \n"); 
	scanf ("%lf %lf %lf", &*h1, &*h2, &*h3); 
	printf ("Enter vector C (c1 c2 c3): \n"); 
	scanf ("%lf %lf %lf", &*k1, &*k2, &*k3); 
} 

/******************************************************************* 
 **	FUNCTION print_output 
 **     PRINTS RESULTS TO SCREEN 
 **		VARIABLES 
 **			a1, a2, a3 = COMPONENTS OF VECTOR A 
 **			b1, b2, b3 = COMPONENTS OF VECTOR B 
 **			c1, c2, c3 = COMPONENTS OF VECTOR C 
 **			d1, d2, d3 =COMPONENTS OF VECTOR D=AxBxC 
 ********************************************************************/ 
 void print_output  (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
 		double c1, double c2, double c3,\ 
 		double d1, double d2, double d3 )
 { 
 	printf ("\n\n\rThe input vectors are:\n\n\ 
 		\r        i       j        k \n\ 
 		\r	%.2lf	%.2lf	 %.2lf \n\ 
		\r	%.2lf	%.2lf	 %.2lf \n\ 
		\r	%.2lf	%.2lf	 %.2lf \n\n\n\n", a1,a2,a3,b1,b2,b3,c1,c2,c3); 
 
	printf ("The results are D=AxBxC:\n\n\ 
		  \r        i       j        k \n\ 
 		\r	%.2lf	%.2lf	 %.2lf \n\ ",d1,d2,d3);	
	}
 
  
