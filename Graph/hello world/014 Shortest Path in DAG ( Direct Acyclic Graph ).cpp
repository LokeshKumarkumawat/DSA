
// BFS
// DAG
// shortest Path in weighted Graph DAG

#include<bits/stdc++.h>
using namespace std;


void toposort(vector<int> adj[], vector<int> &ans , int v,int s){
    
 
    vector<bool> visited(v+1, false);
    queue<int> q;
    vector<int> indree(v, 0);
    
    for(int i=0; i<v;i++){
        for(auto x: adj[i]){
            indree[x]++;
        }
    }
    
    for(int i = 0 ;i<v;i++){
        int d = indree[i];
        if(d == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ans.push_back(f);
        
        for(auto x: adj[f]){
            indree[x]--;
            if(indree[x] == 0){
                q.push(x);
            }
        }
    }
}



void shortestDagPath(vector<int> adj[] , int v, int s){
    
    vector<int> dist(v,INT_MAX);
    vector<int> ans;
    dist[s] = 0;
    
    toposort(adj ,ans, v, s); 
    
    for(int i= 0;i<ans.size();i++){
        for(auto x: adj[ans[i]]){
            if(dist[x] > dist[ans[i]]+ w[ans[i]] ){
                dist[x] = dist[ans[i]] ;
            }
        }
    }
    
    
    cout<<"done";
    
    
    
}



void addAdj(vector<int> adj[], int u, int v,int w){
    adj[u].push_back(v);
    adj[v].push_back(u);
    adj[w].push_back(w);
}

int main(){
    int v = 5;
    vector<int>adj[v];
    
    addAdj(adj,0,1,1);
    addAdj(adj,2,0,2);
    addAdj(adj,3,0,2);


    
    // shortestDagPath(adj,v,0);
    
    shortestDagPath(adj, v,0);
    
    return 0;
}

