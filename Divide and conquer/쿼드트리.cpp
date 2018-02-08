#include<cstdio>
#include<algorithm>

int arr[65][65];

int quad(int a, int b, int N)
{
	bool flag = true;

	for (int i = a; i <a+N && flag; i++)
	{
		for (int j = b; j < b + N; j++)
		{
			if (arr[a][b] != arr[i][j])
			{
				flag = false;
				break;
			}
		}
		}

	if (flag==true)
	{
		printf("%d", arr[a][b]);
	}
	else
	{
		printf("(");
		quad(a, b, N / 2);//왼쪽 위
		quad(a, b + N / 2, N/2);//오른쪽 위
		quad(a + N / 2, b,N/2);//왼쪽 아래
		quad(a + N / 2, b + N / 2, N/2);//오른쪽 아래
		printf(")");
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);

	quad(1, 1, N);
	printf("\n");

	return 0;
}
