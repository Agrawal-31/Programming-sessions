#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int dp[10000];

int solve(int n, int arr[], int m){

	if(n == 0)
		return 0;

	if(n < 0)
		return 1e5;

	if(dp[n] != -1)
		return dp[n];
	

	int ans = INT_MAX;

	for (int i = 0; i < m; ++i)
	{
		ans = min(ans, 1 + solve(n - arr[i], arr, m));
	}

	dp[n] = ans;
	return dp[n];
}


int main(){

	int m;
	cin >> m;

	int arr[m];

	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i];
	}

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	cout << solve(n, arr, m) << endl;

}

