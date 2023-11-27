// Online C++ compiler to run C++ program onli



#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[],int v ,int s){
    vector<bool>visited (v+1,false);
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
    int v = 4;
    vector<int>adj[v];
    
    addAdj(adj,0,1);
    addAdj(adj,0,2);
    addAdj(adj,1,2);
    addAdj(adj,2,3);
    
    printAdj(adj,v);
    
    cout<<"BFS od Adj list"<<endl;
    
    BFS(adj,v,0);
    
    
    
    return 0;
}







// 0 = 1->2->
// 1 = 0->2->
// 2 = 0->1->3->
// 3 = 2->
// BFS od Adj list
// 0 1 2 3 