#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		int n;
		scanf("%d",&n);
		int a[n];
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i=0;i<=n-1;i++)
		{
			int small = a[i],location;
			for (int j=i+1;j<=n-1;j++)
			{
				if (a[j]<small)
				{
					small = a[j];
					location = j;
				}
			}
			int t = a[location];
			a[location] = a[i];
			a[i] = t;
		}
		for (int i=0;i<=n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
}
