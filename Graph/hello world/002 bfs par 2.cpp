// Online C++ compiler to run C++ program onli
#include<bits/stdc++.h>
using namespace std;



void BFS(vector<int> adj[] ,int s,vector<bool> &visited){
    queue<int>q;
    
    visited[s] =true;
    q.push(s);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for(auto x:adj[f]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
}


void BFSdis(vector<int> adj[] ,int v){
    int c = 0;
    vector<bool>visited (v,false);
    
    for(int i =0; i<v;i++){
        if(visited[i] == false){
            BFS(adj,i, visited);
            c++;
        }
    }
    cout<<endl;
    
    cout<<"count of disconnected graph "<<c<<endl;
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
    int v = 7;
    vector<int>adj[v];
    
    addAdj(adj,0,1);
    addAdj(adj,0,2);
    addAdj(adj,1,3);
    addAdj(adj,2,3);
    addAdj(adj,4,5);
    addAdj(adj,4,6);
    addAdj(adj,5,6);
    
    // printAdj(adj,v);
    

    
    BFSdis(adj,v);
    
    
    
    return 0;
}

