// Alice and Bob recently got into running, and decided to compare how much they ran on different days.

// They each ran for N days on ith day, Alice ran Ai, metersand Bob ran Bi meters.

// On each day,

// Alice is unhappy if Bob ran strictly more than twice her distance, and happy otherwise.
// Similarly, Bob is unhappy if Alice ran strictly more than twice his distance, and happy otherwise.

// On how many of the N days were both Aliceand Bob happy ?

// Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i] * 2 || b[i] > a[i] * 2) {
			continue;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}