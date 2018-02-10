#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define SIZE 1001
using namespace std;

int DP[SIZE][SIZE] = { 0, };
vector <int> vec;

int main()
{
	string str1, str2;

	cin >> str1 >> str2;
	str1 = '0' + str1;
	str2 = '0' + str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	printf("%d\n", DP[len1 - 1][len2 - 1]);

	int i = len1 - 1;
	int j = len2 - 1;

	while (DP[i][j] != 0)
	{
		if (DP[i][j] == DP[i][j - 1])
			j--;

		else if (DP[i - 1][j] == DP[i][j])
			i--;

		else {
			vec.push_back(i);
			i--;
			j--;

		}
	}

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		printf("%c", str1[vec[i]]);
	}
	printf("\n");
	return 0;
}
