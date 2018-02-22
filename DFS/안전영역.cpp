#include<cstdio>
#include<cstring>

int arr[101][101] = { 0, };
int safe[101][101] = { 0, };


void area(int n,int m,int k)		/////////////////flood fill 알고리즘사용//////////////////////
{
	if (arr[n][m] <= k || safe[n][m]==1)
	{	return; }
	else {
			safe[n][m] = 1;
			area(n-1, m, k);//위
			area(n+1,m, k);//아래
			area(n,m-1, k);//왼쪽
			area(n,m+1, k);//오른쪽
	}
}

void DFS(int N,int max)
{
	int cnt,result=0;

	for (int i = 0; i <=max; i++)
	{
		cnt = 0;
		memset(safe, 0, sizeof(safe));//배열 초기화

		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{

				if (arr[j][k] >i && (safe[j][k] == 0)) ///////////// DFS알고리즘으로 탐색/////////////
				{
					area(j,k,i);
					cnt++;
				}

				result = (result >= cnt) ? result : cnt;
			}

		}
	}
	printf("%d\n", result);
}

int main()
{
	int N,max=0;
	scanf("%d", &N);//N*N배열

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
			max = max >= arr[i][j] ? max: arr[i][j];//최대 높이
		}
	DFS(N,max);
	return 0;
}
