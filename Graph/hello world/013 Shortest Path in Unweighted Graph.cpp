// BFS


// Online C++ compiler to run C++ program onli

// BFS

// shortest Path in Unweighted Graph

#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> adj[], int v, int s){
    vector<bool> visited(v+1, false);
    vector<int> dist(v,INT_MAX);
    dist[s] = 0;
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        
        for(auto x: adj[f]){
            if(visited[x] == false){
                dist[x] = dist[f] +1;
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
    for(auto y: dist){
        cout<<y<<" ";
    }
    
}

void addAdj(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v = 8;
    vector<int>adj[v];
    
    addAdj(adj,0,1);
    addAdj(adj,0,3);
    addAdj(adj,1,2);
    addAdj(adj,3,4);
    addAdj(adj,3,7);
    addAdj(adj,4,5);
    addAdj(adj,4,6);
    addAdj(adj,4,7);
    addAdj(adj,5,6);
    addAdj(adj,6,7);
    
    shortestPath(adj,v,0);
    
    return 0;
}

