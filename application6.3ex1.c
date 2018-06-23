/* Program for application 6_2 */
 #include <stdio.h>
#define MAX_NUM_PTS 100

int main (void)
{
	int x[MAX_NUM_PTS], num_pts, i, j, count_lower, count_higher, median;
	double sum, mean;
	FILE *infile;

	infile = fopen ("C:\\Users\\user\\Desktop\\programming etc\\about c\\c for enginers\\Chapter6\\Applications\\average.dat", "rt");
	fscanf (infile, "%d", &num_pts);
	for (i=0; i<num_pts; i++) fscanf (infile, "%d", &x[i]);

/*********************************************************
**  CALCULATION OF THE MEAN
*********************************************************/
	sum = 0.0;
	for (i=0; i<num_pts; i++) sum += x[i];
	mean = sum/(double)num_pts;
/*********************************************************
**  CALCULATION OF THE MEDIAN
*********************************************************/

	j=-1;
	while (j<num_pts && count_lower <=((double)(num_pts)/2.) || count_higher <=((double)(num_pts)/2.))
	{
	j++;
	count_lower = 0;
	count_higher = 0;
	for (i=0; i<num_pts; i++)
		{
		if (x[j] <= x[i]) count_higher++;
		if (x[j] >= x[i]) count_lower++;
		}
		
	} 	
	median = x[j];

	printf ("The mean of the values is: %.3lf \n"
		"The median value is:       %d  \n", mean, median);
		return 0;
}
 
