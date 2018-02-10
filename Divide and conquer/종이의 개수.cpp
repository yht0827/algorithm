#include<cstdio>

int arr[2188][2188],zero=0,one=0,_one=0;

void paper(int N,int a,int b)
{
	bool flag = true;

	for (int i = a; i < a + N && (flag); i++)
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
		if (arr[a][b] == -1)
		{
			_one += 1;
		}
		else if (arr[a][b] == 0)
		{
			zero += 1;
		}
		else if(arr[a][b]==1) {
			one += 1;
		}
	}
	else {

		paper(N/3, a , b);//상단 왼쪽
		paper(N/3, a, b+N/3);//상단 가운데
		paper(N / 3, a, b+(N/3)*2);//상단 오른쪽
		paper(N / 3, a+N/3, b);//중앙 왼쪽
		paper(N / 3, a+N/3, b + N / 3);//중앙  가운데
		paper(N / 3, a+N/3, b + (N / 3) * 2);//중앙 오른쪽
		paper(N / 3, a + (N / 3) * 2, b);//하단 왼쪽
		paper(N / 3,a+(N/3)*2 , b + N / 3);//하단 가운데
		paper(N / 3, a + (N / 3) * 2, b + (N / 3) * 2);//하단 오른쪽
	}

}
int main()
{
	int N;
	scanf("%d", &N);	
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &arr[i][j]);

	paper(N,1,1);

	printf("%d\n", _one);
	printf("%d\n", zero);
	printf("%d\n", one);
	
	return 0;
}
