/* this programm calculates (AxB).(CxD)*/

 #include <stdio.h> 
 #include <math.h> 
  
 /******************************************* 
 **	FUNCTION PROTOTYPES 
 *******************************************/ 
  
double dot_product (double g1, double g2, double g3, \ 
		     double h1, double h2, double h3); 
 
void cross_product   (double g1, double g2, double g3,\ 
		      double h1, double h2, double h3,\ 
		      double *k1, double *k2, double *k3); 
		      
void read_input (double *g1, double *g2, double *g3, \ 
		 double *h1, double *h2, double *h3,\ 
		 double *k1, double *k2, double *k3,\
		 double *m1, double *m2, double *m3); 
 
void print_output (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
 		double c1, double c2, double c3,\ 
 		double d1, double d2, double d3,\
 		double result); 
double AxB_CxD(double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
 		double c1, double c2, double c3,\ 
 		double d1, double d2, double d3);
 		
void main(void)
{
	double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,result;
	
	read_input(&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3,&d1,&d2,&d3);
	
	result=AxB_CxD(a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3);
	print_output(a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,result);
} 	


double dot_product (double g1, double g2, double g3,\ 
		     double h1, double h2, double h3 ) 
{ 
	double g_dot_h ; 
	g_dot_h = g1*h1+g2*h2+g3*h3; 
	return (g_dot_h); 
} 	

 void   cross_product (double g1, double g2, double g3,\ 
 		      double h1, double h2, double h3, \ 
 		      double *k1, double *k2, double *k3) 
 { 
	*k1 = g2*h3 - g3*h2; 
	*k2 = -(g1*h3 - g3*h1); 
	*k3 = g1*h2 - g2*h1; 
 } 
 
 
 void read_input (double *g1, double *g2, double *g3,\ 
		 double *h1, double *h2, double *h3,\ 
		 double *k1, double *k2, double *k3,\
		  double *m1, double *m2, double *m3) 
{ 
	printf ("Enter vector A (a1 a2 a3): \n"); 
	scanf ("%lf %lf %lf", &*g1, &*g2, &*g3); 
	printf ("Enter vector B (b1 b2 b3): \n"); 
	scanf ("%lf %lf %lf", &*h1, &*h2, &*h3); 
	printf ("Enter vector C (c1 c2 c3): \n"); 
	scanf ("%lf %lf %lf", &*k1, &*k2, &*k3); 
	printf ("Enter vector D (d1 d2 d3): \n"); 
	scanf ("%lf %lf %lf", &*m1, &*m2, &*m3); 
} 

void print_output (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
		double c1, double c2, double c3,\ 
 	    double d1, double d2, double d3,\
 		double result) 
 { 
 	printf ("\n\n\rThe input vectors are:\n\n" 
 		"\r        i       j        k \n" 
 		"\r	%.2lf	%.2lf	 %.2lf \n "
		"\r	%.2lf	%.2lf	 %.2lf \n "
		"\r	%.2lf	%.2lf	 %.2lf \n"
		"\r	%.2lf	%.2lf	 %.2lf \n\n\n\n", a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3); 
 
	printf ("The results are:\n\n" 
		   "(AxB).(CxD)=                = %lf \n",result); 
} 

double AxB_CxD(double a1, double a2, double a3,\ 
			double b1, double b2, double b3,\ 
 			double c1, double c2, double c3,\ 
 			double d1, double d2, double d3)
 	{
 		double w1,w2,w3,e1,e2,e3,result;
 		
		 cross_product(a1,a2,a3,b1,b2,b3,&w1,&w2,&w3);
		  cross_product(c1,c2,c3,d1,d2,d3,&e1,&e2,&e3);
		  result=dot_product(w1,w2,w3,e1,e2,e3);
		  return result;
		 
	 }
