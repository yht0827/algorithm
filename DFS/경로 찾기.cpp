#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int arr[101][101];//입력 배열
int visited[101][101] = { 0, }; // 출력 배열 		
vector<vector<int>> a;				//DFS를 수행하기 위해 값 저장

void dfs(int n,int curr)//n행,노드
{	
	for (int next : a[curr])
		if (!visited[n][next]){

			visited[n][next] = 1;
			dfs(n,next);
			}
}
int main()
{
	scanf("%d", &N);
	a.resize(N + 1);//vector배열 개수 설정

	for (int i = 1; i<= N; i++)
	{
		for (int j = 1; j<= N; j++)
		{
			scanf("%d",&arr[i][j]);

			if (arr[i][j] == 1)
				a[i].push_back(j);
		}
	}
	memset(visited, 0, sizeof(visited));//visited배열 초기화

	for(int i=1;i<=N;i++)//1행부터 수행
	dfs(i,i);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", visited[i][j]);//결과 출력
		}
		printf("\n");
	}

	return 0;
}
