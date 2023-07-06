// Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
// Each throw produces an outcome between 1 and 6.

// for example, if n = 3, there are 4 ways:
// 1 + 1 + 1
//1 + 2
//2 + 1
//3

// solve using dynamic programming

#include <iostream>
#include <vector>
using namespace std;

int countWays(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << countWays(n) << endl;
	return 0;
}