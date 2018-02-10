#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, *arr, i;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int)*(n + 1));

	arr[1] = 0;
	for (i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
		{
			if (arr[i]>arr[i / 2] + 1)
				arr[i] = arr[i / 2] + 1;
		}
		if (i % 3 == 0)
		{
			if (arr[i]>arr[i / 3] + 1)
				arr[i] = arr[i / 3] + 1;
		}
	}

	printf("%d\n", arr[n]);

	return 0;
}
