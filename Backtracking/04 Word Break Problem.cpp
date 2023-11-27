// dp solution


class Solution
{
	public:
		unordered_map<string, int> dp;

	bool wordBreak(string s, vector<string> &wordDict)
	{
		int x = 0;

		x = lve(s, wordDict);
		if (x == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	int lve(string s, vector<string> &b)
	{
		int n = s.length();
		if (n == 0) return 1;

		if (dp[s] != 0) return dp[s];

		for (int i = 1; i <= n; i++)
		{
			int f = 0;
			string ss = s.substr(0, i);
			for (int j = 0; j < b.size(); j++)
			{
				if (ss.compare(b[j]) == 0)
				{
					f = 1;
					break;
				}
			}

			if (f == 1 && lve(s.substr(i, n - i), b) == 1)
			{
				return dp[s] = 1;
			}
		}

		return dp[s] = -1;
	}
};