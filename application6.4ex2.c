 /**************************************************************************
***************************************************************************
**	APPLICATION PROGRAM TO CALCULATE             
**	THE RELATIONSHIP BETWEEN THE VEHICLE DENSITY AND NUMBER
**	OF ACCIDENTS OF A STRETCH OF HIGHWAY. 
**	TWO LINES ARE USED TO FIT THE DATA.  ONE THAT GOES FROM 0 TO 
**	THE PEAK NUMBER OF ACCIDENTS AND THE OTHER FROM THE PEAK TO 
**	THE LAST DATA POINT.
**                                                      
**         PROGRAMMER NAMES       REVISION DATES        
**                                                      
**                                                      
***************************************************************************
**************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_NUM_PTS 50
/**************************************************************************
**	FUNCTION PROTOTYPES
**************************************************************************/

void readinput (double r[], double s[], int *num_pts);
void printresult(double slope1, double intercept1, \
					  double slope2, double intercept2,\
					  double accidents_max,\
					  double density_at_accdts_max);
void findmax (double a[], double *a_max, int *i_at_a_max, int num_pts);
void bestfit (double x[], double y[], int i_left, int i_right,\
				  double *m, double *b);
void newinput_predict (double m1,double m2,double b1,double b2);
/*************************************************************************************
**	FUNCTION main
**	CALLS FUNCTIONS TO:
**	READ THE DATA POINTS OF VEHICLE DENSITY AND NUMBER OF ACCIDENTS
**	FIND THE MAXIMUM NUMBER OF ACCIDENTS
**	FIT A STRAIGHT LINE THROUGH THE FIRST PART OF THE DATA (UP TO THE PEAK
**		NUMBER OF ACCIDENTS)
**	FIT A STRAIGHT LINE THROUGH THE SECOND PART OF THE DATA (FROM THE 
PEAK
**		NUMBER OF ACCIDENTS TO THE LAST POINT)
**	PRINT THE SLOPES AND INTERCEPTS OF THE TWO LINES
************************************************************************************/


int main(void)
{
	double x[MAX_NUM_PTS], y[MAX_NUM_PTS], m1, m2, b1, b2;
	double y_max;
	int  i_at_y_max, num_pts;

	readinput(x,y,&num_pts);
	findmax(y,&y_max,&i_at_y_max,num_pts);
	bestfit(x,y,0,i_at_y_max,&m1,&b1);
	bestfit(x,y,i_at_y_max,num_pts-1,&m2,&b2);
	printresult (m1,b1,m2,b2,y_max,x[i_at_y_max]);
	newinput_predict (m1, m2, b1, b2);
	return 0;
}
/*****************************************************************************
**	FUNCTION readinput
**	READS THE INPUT DATA POINTS AND COUNTS THE NUMBER OF POINTS
**		VARIABLES - INPUT
**		none
**		VARIABLES - RETURNED THROUGH PARAMETER LIST
**			r[ ] = x values of data points = vehicle density
**			s[ ] = y values of data points = number of accidents
**			*numpts = number of data points
*****************************************************************************/


void readinput (double r[], double s[],int *num_pts)
{
	int i;
	FILE *infile;
	infile = fopen ("bestline.dat","rt");

  i=0;
  while ((fscanf(infile,"%lf %lf",&r[i],&s[i]))!= EOF) i++;
  *num_pts = i;
  /*printf ("num_pts=%d\n",*num_pts);*/
}
/*****************************************************************************
**	FUNCTION printresult
**	PRINTS THE SLOPES AND INTERCEPTS OF THE BEST FIT LINES.
**	DISPLAYS THE MAXIMUM NUMBER OF ACCIDENTS AND 
**	THE VEHICLE DENSITY AT THE MAXIMUM NUMBER OF ACCIDENTS
**		VARIABLES - INPUT
**		slope1, intercept1 = slope and intercept of first line (from 0 to peak accidents)
**		slope2, intercept2 = slope and intercept of second line (from peak accidents to last pt.
**		accidents_max = maximum number of accidents in data set
**		density_at_accdts_max = vehicle density at maximum number of accidents
**		VARIABLES - RETURNED
**		none
*****************************************************************************/


void printresult(double slope1, double intercept1, \
					  double slope2, double intercept2,\
					  double accidents_max,\
					  double density_at_accdts_max)
{
	printf ("The first line is y = %.3lfx + %.3lf \n\
			 \rThe second line is y = %.3lfx + %.3lf \n\n\
			 \rThe maximum number of accidents is %.1lf \n\
			 \rat a vehicle density of %.2lf\n",
			 slope1, intercept1, slope2, intercept2,
			 accidents_max, density_at_accdts_max);
}
/*****************************************************************************
**	FUNCTION findmax
**	FINDS THE MAXIMUM VALUE IN A 1-D ARRAY.
**		VARIABLES - INPUT
**		a[ ] = array containing number of accidents
**		num_pts = number of points in the array
**		VARIABLES - RETURNED THROUGH THE PARAMETER LIST
**		*a_max = maximum number of accidents
**		*i_at_a_max = array index at maximum number of accidents
*****************************************************************************/

void findmax ( double a[],\
					double *a_max, int *i_at_a_max, int num_pts)
{
	int i;
	*a_max = 0.0;
	for (i=0; i<num_pts; i++)
		{
		if (a[i] >= *a_max)
			{
			*a_max = a[i];
			*i_at_a_max = i;
			}
		}
}
/*****************************************************************************
**	FUNCTION bestfit
**	FINDS A BEST FIT STRAIGHT LINE THROUGH A SET OF X, Y DATA POINTS
**		VARIABLES - INPUT
**		x[ ] = array containing vehicle density
**		y[ ] = array containing number of accidents
**		i_left, i_right = array indices, all x-y values of data points from i_left 
**				through i_right are included in the best fit analysis
**		VARIABLES - RETURNED THROUGH THE PARAMETER LIST
**		*m = slope of the best fit line
**		*b = intercept of best fit line
**		OTHER VARIABLES
**		c,d,e,f = intermediate values for best fit calculation - see accompanying documents
**		n = number of data points used in best fit evaluation
*****************************************************************************/


void bestfit (double x[], double y[], int i_left, int i_right,\
				  double	*m, double *b)
{
		double c, d, e, f, n;
		int i;
		c=d=e=f=0.0;

		for (i=i_left; i<=i_right; i++)
			{
			c += x[i];
			d += y[i];
			e += x[i]*x[i];
			f += x[i]*y[i];
			}

		n = i_right - i_left +1;
		*m = (n*f - c*d)/(n*e - c*c);
		*b = (d*e - c*f)/(n*e - c*c);

}

void newinput_predict (double m1,double m2,double b1,double b2)
{
	double x1,x2,y1;
	printf("Please enter number of accidents\n");
	scanf("%lf",&y1);
	
	x1=(y1-b1)/m1;
	x2=(y1-b2)/m2;
	printf("the predictions of car density  is %.2lf and %.2lf\n", x1,x2);
}
 
