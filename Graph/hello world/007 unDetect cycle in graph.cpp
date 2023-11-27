// dfs



// Online C++ compiler to run C++ program onli
#include <bits/stdc++.h>
using namespace std;

bool dfsRec(vector<int> adj[], int i, vector<bool> &visited, int p)
{
	visited[i] = true;
	// cout<<i<<" ";

	for (auto x: adj[i])
	{
		if (visited[x] == false)
		{
			if (dfsRec(adj, x, visited, i))
			{
				return true;
			}
		}
		else if (x != p && visited[x] == true)
		{
			return true;
		}
	}

	return false;
}

bool isCycle(vector<int> adj[], int v, int s)
{
	vector<bool> visited(v, false);

	for (int i = 0; i < v; i++)
	{
		if (visited[i] == false)
		{
			if (dfsRec(adj, i, visited, -1))
			{
				return true;
			}
		}
	}

	return false;

}

void addAdj(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printAdj(vector<int> adj[], int v)
{
	for (int i = 0; i < v; i++)
	{
		cout << i << " = ";
		for (auto x: adj[i])
		{
			cout << x << "->";
		}

		cout << endl;
	}
}

int main()
{
	int v = 7;
	vector<int> adj[v];

	addAdj(adj, 0, 1);
	addAdj(adj, 1, 2);
	addAdj(adj, 2, 3);
	addAdj(adj, 3, 4);
	addAdj(adj, 4, 5);
	addAdj(adj, 4, 6);

	// printAdj(adj,v);

	ans = isCycle(adj, v, 0);
	cout << ans << endl;

	return 0;

}


