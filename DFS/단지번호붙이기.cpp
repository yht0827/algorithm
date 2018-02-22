#include<cstdio>
#include<algorithm>
using namespace std;

int arr[27][27] = { 0, };//맨 밑에 25번째 행 때문에 26번째 행에 0을 넣어줘야함 
int DFS[27][27] = { 0, };
int house[626];
int N;
int temp;

int flood(int i, int j)
{

	if (arr[i][j] == 0 || DFS[i][j] == 1)
		return 0;

	else {

		DFS[i][j] = 1;
		temp++;

		flood(i - 1, j);//위
		flood(i + 1, j);//아래
		flood(i, j - 1);//왼쪽
		flood(i, j + 1);//오른쪽	
	}

	return temp;
}


void solve(int N)
{
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 1 && DFS[i][j] == 0)
			{
				temp = 0;
				house[cnt++] = flood(i, j);	//집 수 반환
			}
		}
	}
	printf("%d\n", cnt);//총 단지수

	sort(house, house + cnt);//단지 정렬
	for (int i = 0; i < cnt; i++)
		printf("%d\n", house[i]);
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);

	solve(N);
	return 0;
}
