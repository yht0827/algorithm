#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int N, input, arr[10001], DP[10001], MAX = 0;

	cin >> N;

	arr[0] = 0;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> input;
		arr[i] = input;
	}

	DP[0] = 0;
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	for (int i = 3; i<N + 1; i++)
	{
		MAX = max(DP[i - 3] + arr[i - 1] + arr[i], DP[i - 1]);
		DP[i] = max(MAX, DP[i - 2] + arr[i]);
	}

	cout << DP[N] << " ";

	return 0;
}