void dvig(char **a)
{
	char last=a[height-1][0];
	for (int i=height-1;i>0;i--)
		a[i][0]=a[i-1][0];
	a[0][0]=last;
	last=a[height-1][width-1];
	for (int i=height-1;i>0;i--)
		a[i][width-1]=a[i-1][width-1];
	a[0][width-1]=last;
	
}