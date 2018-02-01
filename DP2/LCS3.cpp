#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define SIZE 101
using namespace std;

int DP[SIZE][SIZE][SIZE] = {0, };
string str1,str2,str3;

int main()
{
	int LCS = 0;

	cin >> str1 >> str2>>str3;

	str1 = '0' + str1;
	str2 = '0' + str2;
	str3 = '0' + str3;

	int len1 = str1.size();
	int len2 = str2.size();
	int len3 = str3.size();

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			for (int k = 1; k < len3; k++)
			{
				if ((str1[i] == str2[j]) && (str2[j] == str3[k]) && (str1[i] == str3[k]))
				{
					DP[i][j][k] = DP[i - 1][j - 1][k - 1]+ 1;
				}
				else {
					DP[i][j][k] = max(DP[i - 1][j][k],max(DP[i][j - 1][k],DP[i][j][k-1]));
				}

			}
		}
	}

	printf("%d\n",DP[len1 - 1][len2 - 1][len3-1]);

	return 0;
}