// algo:  1> Push the first node in the queue

//           2> Pop the front element of the queue and store it in a variable frontNode

// 3> Mark true corresponding to the key in the visited map

// 4> Store the frontNode in ans vector

// 5> Push neighbor in the queue for the frontNode if the corresponding mapping in the visited map is false 

// 6> repeat the steps for each node

 

#include<bits/stdc++.h>

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges){
    for(int i =0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList,    unordered_map<int, bool> &visited    ,vector<int>&ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
//         store front node in the ans
        ans.push_back(frontNode);
        
//         traverse all neighbours of the front node
        for(auto i : adjList[frontNode]){
           if(!visited[i]){
               q.push(i);
              visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   
    unordered_map<int, set<int>> adjList;
    vector<int>ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);
    
//     traverse all components of the graph
    for(int i =0;i<vertex; i++){
        if(!visited[i])
            bfs(adjList, visited, ans, i);
    }
    return ans;
}






