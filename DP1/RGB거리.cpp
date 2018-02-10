#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int N, vec[1001][3] = { 0, };

	cin >> N;

	vector<vector<int> > DP(N+1, vector<int>(3,0));

	for (int i = 1; i <=N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> vec[i][j];
		
	}

	for (int i = 1; i <=N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				DP[i][0] = min(DP[i - 1][1],DP[i - 1][2]) + vec[i][0];
			}
			else if(j == 1)
			{
				DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + vec[i][1];
			}
			else {
				DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + vec[i][2];
			}
		}
	}
	printf("%d\n", min(DP[N][0], min(DP[N][1], DP[N][2])));

	return 0;
}
