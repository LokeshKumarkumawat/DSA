

973. K Closest Points to Origin
https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
	public:
		vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
		{
			priority_queue<pair<int, vector< int >>> maxh;

			int n = points.size();

			for (int i = 0; i < n; i++)
			{
				maxh.push({ points[i][0] *points[i][0] + points[i][1] *points[i][1],
					{
						points[i][0], points[i][1]
					} });
				if (maxh.size() > k)
				{
					maxh.pop();
				}
			}

			vector<vector < int>> ans;

			while (maxh.size() > 0)
			{
				ans.push_back(maxh.top().second);
				maxh.pop();
			}

			return ans;
		}
};