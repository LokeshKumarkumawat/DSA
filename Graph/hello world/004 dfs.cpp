// Online C++ compiler to run C++ program onli
#include<bits/stdc++.h>
using namespace std;



void dfsRec(vector<int> adj[] ,int i,vector<bool> &visited){
    
    visited[i] =true;
    cout<<i<<" ";
    
    for(auto x:adj[i]){
        if(visited[x] == false){

            dfsRec(adj,x,visited);
        }
    }
}


void dfs(vector<int> adj[] ,int v , int s){
    vector<bool>visited (v,false);
    
    for(int i =0; i<v;i++){
        if(visited[i] == false){
            dfsRec(adj,i, visited);
        }
    }
    cout<<endl;
    
}



void addAdj(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printAdj(vector<int> adj[] ,int v ){
    for(int i = 0; i<v;i++){
        cout<<i<<" = ";
        for(auto x: adj[i]){
            cout<<x<<"->";
        }
        cout<<endl;
    }
}


int main(){
    int v = 5;
    vector<int>adj[v];
    
    addAdj(adj,0,1);
    addAdj(adj,0,2);
    addAdj(adj,1,3);
    addAdj(adj,1,4);
    addAdj(adj,2,3);
    addAdj(adj,3,4);
    
    
    // printAdj(adj,v);
    

    
     dfs(adj,v,0);
    
    
    
    return 0;
}

