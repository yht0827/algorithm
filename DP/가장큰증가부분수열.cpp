#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> vec, DP;

int main(void)
{

	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		vec.push_back(input);
	}

	DP = vector<int>(vec.begin(), vec.end());

	int MAX = DP[0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[j] < vec[i] && (DP[i] < DP[j] + vec[i]))
				DP[i] = DP[j] + vec[i];
		}
		MAX = max(MAX, DP[i]);
	}
	cout << MAX << endl;

	return 0;
}