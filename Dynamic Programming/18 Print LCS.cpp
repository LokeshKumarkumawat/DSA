#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; 

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string lcs = ""; 
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs += X[i - 1]; // insert in string 
			i--, j--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--; // move to the larger side 
			else
				i--;
		}
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/