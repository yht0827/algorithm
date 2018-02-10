#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#define SIZE 1001
using namespace std;

int DP[SIZE][SIZE] = {0, };
string str1, str2;

int main()
{
	int LCS = 0;

	cin>> str1 >> str2;

	str1 = '0'+ str1;
	str2 = '0'+ str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				DP[i][j] = DP[i - 1][j - 1]+1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}

		}
	}
		
	printf("%d\n", DP[len1-1][len2-1]);

	return 0;
}
