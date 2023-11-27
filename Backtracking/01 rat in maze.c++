bool isSafe(int x,int y,vector<vector<bool>> &visited,vector < vector < int >> & arr,int n){
    if((x>=0 && y>=0)&&(x<n && y<n)&&(visited[x][y]==0)&&(arr[x][y]==1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x,int y,vector < vector < int >> & arr, int n,vector <string> &ans,vector<vector<bool>> &visited,string path){
    
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
visited[x][y] = 1;    
    // down
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path+'D');
//         path.pop_back();
    }
    //left
    if(isSafe(x,y-1,visited,arr,n)){  
        solve(x,y-1,arr,n,ans,visited,path+'L');
    }
    
    //right
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path+'R');
    }
    //up
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path+'U');
   }
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    string path ="";
    if(arr[0][0] == 0){
       return ans;
    }
   solve(0,0,arr,n,ans,vis,path);
    return ans;
}