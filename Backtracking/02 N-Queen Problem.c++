

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int>> &board,int n){
    int x=row;
    int y=col;
  while(y>=0){
      if(board[x][y]==1)
          return false;
      y--;
  }
    
    x=row;
    y=col;
    while(x>=0 && y>=0){ 
        if(board[x][y]==1)
            return false;
        y--;
        x--;
    }
    
       x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1)
            return false;
        y--;
        x++;
    }
    return true;
}
void solve(int col, vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    if(col==n){
      addSolution(ans,board,n);
        return;  
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,ans,board,n);
            //backtracking
            board[row][col]=0;
        }
        
    }
}


vector<vector<int>> nQueens(int n)
{
	// Write your code here
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,ans,board,n);
    return ans;
	
}
































//optemmization


#include<unordered_map>
void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    
    ans.push_back(temp);
}

bool safeToPlaceQ(int row,int col,vector<vector<int>> &board,int n,
          unordered_map<int,bool> &m1, unordered_map<int,bool> &m2 ,unordered_map<int,bool> &m3){
    
  return (m1[row]==false && m2[row+col]==false && m3[n-1+col-row]==false);   
}



void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n, unordered_map<int,bool> &m1 ,unordered_map<int,bool> &m2 ,unordered_map<int,bool> &m3){
    
    //base case
    if(col==n){
        addSolution(ans,board,n);
        return;
    }
         
    //Solve 1 case rest Recursion will do
    for(int row=0;row<n;row++){
        if(safeToPlaceQ(row,col,board,n,m1,m2,m3)){
            //if True place the Q
            board[row][col]=1;
            m1[row]=true;
            m2[row+col]=true;
            m3[n-1+col-row]=true;
            //rec call for the next col
            solve(col+1,ans,board,n,m1,m2,m3);
            //backtrack step if at somepoint not possible to place Q
            board[row][col]=0;
            m1[row]=false;
            m2[row+col]=false;
            m3[n-1+col-row]=false;
        }
    }
}


vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n,vector<int>(n,0));
    //Initialize n*n board , all with value 0.
    vector<vector<int>> ans;
    
    //Three maps to check queen attack
    unordered_map<int,bool> m1,m2,m3;
    solve(0,ans,board,n,m1,m2,m3);//starting with col-0.
    
    return ans;
}