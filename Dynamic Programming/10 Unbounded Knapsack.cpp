#include <bits/stdc++.h>
using namespace std;

int Un_knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; 

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			// base case
			if (i == 0 || j == 0) 
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { 
				int val1 = val[i - 1] + t[i][j - wt[i - 1]]; 
				int val2 = t[i - 1][j]; 
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) 
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][W];
}

signed main() {
	int n; cin >> n; 
	int val[n], wt[n]; 
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; 

	cout << Un_knapsack(wt, val, W, n) << endl;
	return 0;
}
