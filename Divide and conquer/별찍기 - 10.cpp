#include<cstdio>

int arr[2188][2188];

int star(int N,int a,int b)
{
	if (N == 1)
	{
		arr[a][b] = 1;

	}
	else {
		
		star(N / 3, a, b);	//상단 왼쪽
		star(N / 3, a, b+N/3); // 상단 가운데
		star(N / 3, a, b+(N/3)*2);// 상단 오른쪽
		star(N / 3, a + N / 3, b); // 중앙 왼쪽
												//중앙 가운데
		star(N / 3, a + N / 3, b + (N / 3) * 2);//중앙 오른쪽
		star(N / 3, a + (N / 3) * 2, b);//하단 왼쪽
		star(N / 3, a + (N / 3) * 2, b+(N/3));//하단 가운데
		star(N / 3, a + (N / 3) * 2, b+(N / 3)*2);//하단 오른쪽
	}
	return 0;
}


int main()
{

	int N;
	scanf("%d", &N);
	star(N,1,1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=N; j++)
		{
			if (arr[i][j] == 1)
				printf("*");
			else {
				printf(" ");
			}
			}
	
		printf("\n");
	}
		
	return 0;
}
