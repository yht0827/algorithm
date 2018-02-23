#include<cstdio>
#include<cstring>

int arr[51][51];
int visited[51][51];
int N, T, M, K, x, y;

void flood(int n,int m)
{
	if (arr[n][m] == 0 || visited[n][m] == 1 || n< 0 || m< 0)
	{
		return;
	}
	else
	{
		visited[n][m] = 1;

		if (n!=0)
			flood(n-1,m);//위
		
		if(m!=0)
			flood(n,m-1);//왼쪽
		
			flood(n,m+1);//오른쪽
			flood(n+1,m);//아래


	}
}



void worm(int M,int N)
{
	int cnt = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && visited[i][j] == 0)
			{
				flood(i,j);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

int main()
{
	
	scanf("%d", &T);//테스트 수
	
	for (int i = 1; i <= T; i++)
	{
	
		
		scanf("%d %d %d", &M, &N,&K);//가로 세로 길이, 위치의 개수
		
		memset(arr, 0, sizeof(arr));//배열 초기화
		memset(visited, 0, sizeof(visited));

		for (int j = 1; j <= K; j++)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		worm(M,N);	
	}

	return 0;
}
