/* Program for Application exercises 4 */ 
 /***************************************************************** 
**  Program to calculate the root of functions between xa and xb 
******************************************************************/ 
#include <math.h> 
#include <stdio.h> 
 
double y(double x); 
void find_root(double xa, double xb, double error); 
 
int main(void) 
{ 
	double xa=-5, xb=15, tolerance=0.01; 
 	find_root(xa, xb, tolerance); 
 	return 0;
} 
 
/***************************************************************** 
**  Function y uses the equation of the curve for which the root is desired 
**  This function must be modified to test other functions. 
*****************************************************************/ 
 
double y(double x) 
{ 
	return (-2*x+5); 
} 
 
 
/***************************************************************** 
**  Function find_root calls function y to get the values of ya and yb then finds xc half 
**way between xa and xb.  It then repeatedly switches xa, xb and xc around based on  
**the calculated values of y at these x's 
*****************************************************************/ 
 
void find_root(double xa, double xb, double error) 
{ 
	double ya, yb, xc, yc; 
	 
	while (1) 
		{ 
		ya=y(xa); 
		yb=y(xb); 
		if (ya>yb) 
			{ 
			xc=(xa+xb)/2.0; 
			yc=y(xc); 
			printf("xa=%6.2f\txb=%6.2f\txc=%6.2f----\tya=%6.2f\tyb=%6.2f\tyc=%6.2f\n", 
			xa,xb,xc,ya,yb,yc); 
 
			if ( fabs(yc) < error) break; /* check whether the absolute value of yc <  
			error? */ 
			if (ya*yc>0) xa=xc; 
			else         xb=xc; 
			} 
		else break; 
		} 
	printf("The root is =%6.2f\n",xc); 
	} 
 
     
 
