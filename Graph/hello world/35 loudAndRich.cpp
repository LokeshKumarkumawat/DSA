Solution
{
	public:
		vector<int> loudAndRich(vector<vector < int>> &richer, vector< int > &quiet)
		{
			int n = quiet.size();

			vector<int> indgree(n, 0);
			vector<int> dist(n, INT_MAX);
			queue<int> q;

			vector<int> adj[n];
			for (auto x: richer)
			{
				vector<int> data = x;
				int a = data[0];
				int b = data[1];
				adj[a].push_back(b);
				indgree[b]++;
			}

			for (int i = 0; i < n; i++)
			{
				dist[i] = i;
				if (indgree[i] == 0)
				{
					q.push(i);
				}
			}

			while (!q.empty())
			{
				int f = q.front();
				q.pop();

				for (auto x: adj[f])
				{
					if (quiet[dist[x]] > quiet[dist[f]])
					{
						dist[x] = dist[f];
					}

					indgree[x]--;

					if (indgree[x] == 0)
					{
						q.push(x);
					}
				}
			}

			return dist;

		}
    
};
			