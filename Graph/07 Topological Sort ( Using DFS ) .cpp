#include<bits/stdc++.h>
void find(int node,stack<int>&st,vector<int>&vis,vector<int>adj[])
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
			find(it,st,vis,adj);
	}
	st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
	vector<int>adj[nodes];
	for(int i = 0; i < edges; i++)
	{
		adj[graph[i][0]].push_back(graph[i][1]);
	}
	
	stack<int>st;
	vector<int>vis(nodes,0);
	for(int i=0;i<nodes;i++)
	{
		if(!vis[i])
			find(i,st,vis,adj);
	}
	vector<int>res(nodes);
	while(!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;
}