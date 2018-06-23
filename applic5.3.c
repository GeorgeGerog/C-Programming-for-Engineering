/* Program for Application 5_3*/ 
    
 /************************************************************************** 
*************************************************************************** 
**         APPLICATION PROGRAM TO CALCULATE              
**         AREA OF PARALLELOGRAM AND VOLUME OF           
 **         PARALLELEPIPED DEFINED BY VECTORS A,B AND C   
 **         AREA = LENGTH OF (A CROSS B)                  
 **         VOLUME = ABS VALUE OF (A DOT (B CROSS C))     
 **                                                       
 **         PROGRAMMER NAMES       REVISION DATES         
 **                                                       
 **                                                       
 *************************************************************************** 
 **************************************************************************/ 
  
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
 
double vector_magnitude (double g1, double g2, double g3); 
  
 double area_parallelogram (double g1, double g2, double g3,\ 
 			double h1, double h2, double h3); 
 
double volume_parallelepiped (double g1, double g2, double g3,\ 
			       double h1, double h2, double h3,\ 
			       double k1, double k2, double k3); 
 
void read_input (double *g1, double *g2, double *g3, \ 
		 double *h1, double *h2, double *h3,\ 
		 double *k1, double *k2, double *k3); 
 
void print_output (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
 		double c1, double c2, double c3,\ 
 		double area, double volume); 
  
 /************************************************************************************ 
 **	FUNCTION main 
 **		VARIABLES 
 **			a1, a2, a3 = COMPONENTS OF VECTOR A 
 **			b1, b2, b3 = COMPONENTS OF VECTOR B 
 **			c1, c2, c3 = COMPONENTS OF VECTOR C 
**			area          = AREA OF PARALLELOGRAM DEFINED BY A AND B 
**			volume     = VOLUME OF PARALLELEPIPED DEFINED BY A,B AND C 
*************************************************************************************/ 
  
 void main (void) 
 { 
	double a1, a2, a3, b1, b2, b3, c1, c2, c3, area, volume; 
	read_input (&a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3); 
	area = area_parallelogram (a1,a2,a3,b1,b2,b3); 
	volume = volume_parallelepiped (a1,a2,a3,b1,b2,b3,c1,c2,c3); 
	print_output (a1,a2,a3,b1,b2,b3,c1,c2,c3,area,volume); 
} 
 
/******************************************************************* 
**	FUNCTION dot_product 
**   CALCULATES THE DOT PRODUCT OF TWO VECTORS G AND H 
**		VARIABLES - INPUT 
**			g1, g2, g3 = COMPONENTS OF VECTOR G 
 **			h1, h2, h3 = COMPONENTS OF VECTOR H 
 **		RETURN 
 **			SCALAR VALUE OF THE DOT PRODUCT OF G AND H 
 *********************************************************************/ 
 
double dot_product (double g1, double g2, double g3,\ 
		     double h1, double h2, double h3 ) 
{ 
	double g_dot_h ; 
	g_dot_h = g1*h1+g2*h2+g3*h3; 
	return (g_dot_h); 
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
**	FUNCTION vector_magnitude 
**   CALCULATES THE MAGNITUDE OF A VECTOR G 
**		VARIABLES - INPUT 
**			g1, g2, g3 = COMPONENTS OF VECTOR G 
**		RETURN 
**			SCALAR VALUE OF THE MAGNITUDE OR LENGTH OF G 
*********************************************************************/ 
 
double vector_magnitude (double g1, double g2, double g3) 
{ 
	double mag; 
	mag = sqrt (g1*g1+g2*g2+g3*g3); 
	return (mag); 
} 
 
 
/******************************************************************* 
 **	FUNCTION area_parallelogram 
 **   CALCULATES THE AREA OF A PARALLELOGRAM DEFINED BY 
 **   TWO VECTORS G AND H 
 **   AREA = MAGNITUDE OF (G CROSS H) 
 **		VARIABLES - INPUT 
 **			g1, g2, g3 = COMPONENTS OF VECTOR G 
 **			h1, h2, h3 = COMPONENTS OF VECTOR H 
 **     RETURN 
 **        AREA OF THE PARALLELOGRAM 
 **     FUNCTION CALLS 
 **        CALLS cross_product TO CALCULATE G CROSS H 
 **        CALLS vector_magnitude TO GET MAGNITUDE OF (G CROSS H) 
 ** 
 *********************************************************************/ 
  
double area_parallelogram (double g1, double g2, double g3,\ 
			double h1, double h2, double h3) 
{ 
	double k1, k2, k3, area; 
	cross_product (g1,g2,g3,h1,h2,h3,&k1,&k2,&k3 ); 
	area = vector_magnitude (k1,k2,k3); 
	return (area); 
} 
 
 
 
 
 
/******************************************************************* 
**	FUNCTION volume_parallelepiped 
**   CALCULATES THE VOLUME OF A PARALLELEPIPED DEFINED BY 
**   THREE VECTORS G, H AND K 
**   VOLUME = ABS VALUE OF [G DOT (H CROSS K)] 
 **		VARIABLES - INPUT 
 **			g1, g2, g3 = COMPONENTS OF VECTOR G 
**			h1, h2, h3 = COMPONENTS OF VECTOR H 
**			k1, k2, k3 = COMPONENTS OF VECTOR K 
**			d1, d2, d3 = COMPONENTS OF VECTOR D 
**     RETURN 
**        VOLUME OF THE PARALLELEPIPED 
**     FUNCTION CALLS 
**        CALLS cross_product TO CALCULATE D = H CROSS K 
**        CALLS dot_product TO GET [G DOT D] 
** 
*********************************************************************/ 
 
double volume_parallelepiped (double g1, double g2, double g3, \ 
 			       double h1, double h2, double h3,\ 
			       double k1, double k2, double k3) 
{ 
	double d1,d2,d3,volume; 
	cross_product (h1,h2,h3,k1,k2,k3,&d1,&d2,&d3); 
	volume = fabs(dot_product (g1,g2,g3,d1,d2,d3)); 
	return (volume); 
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
 **			area       = area of parallelogram 
 **			volume     = volume of parallelepiped 
 ********************************************************************/ 
 void print_output (double a1, double a2, double a3,\ 
		double b1, double b2, double b3,\ 
		double c1, double c2, double c3,\ 
 		double area, double volume) 
 { 
 	printf ("\n\n\rThe input vectors are:\n\n\ 
 		\r        i       j        k \n\ 
 		\r	%.2lf	%.2lf	 %.2lf \n\ 
		\r	%.2lf	%.2lf	 %.2lf \n\ 
		\r	%.2lf	%.2lf	 %.2lf \n\n\n\n", a1,a2,a3,b1,b2,b3,c1,c2,c3); 
 
	printf ("The results are:\n\n\ 
		  \rArea of parallelogram (AxB)                = %lf \n\ 
		  \rVolume of parallelepiped (abs(A dot (BxC)) = %lf\n\n",\ 
		   area, volume); 
} 
 
  
 
