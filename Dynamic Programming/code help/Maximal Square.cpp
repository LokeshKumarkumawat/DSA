// WORNG











class Solution {
public:
    
    int solve(vector<vector<char>>& mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int right = solve(mat,i,j+1,maxi);
        int down = solve(mat,i+1,j,maxi);
        int di = solve(mat,i+1,j+1,maxi);
        
        if(mat[i][j] == '1'){
            int ans = 1+min(right,min(down,di));
            maxi = max(maxi,ans);
            return ans;
            
        }else{
            return 0;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        solve(matrix,0,0,maxi);
        
        return maxi;
    }
};


//////////////////////////
// momo
// worng
class Solution {
public:

    int solve(vector<vector<char>>& mat,int i,int j,int &maxi,vector<vector<int>>&t){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int right = solve(mat,i,j+1,maxi,t);
        int down = solve(mat,i+1,j,maxi,t);
        int di = solve(mat,i+1,j+1,maxi,t);
        
        if(mat[i][j] == '1'){
            t[i][j] = 1+min(right,min(down,di));
            maxi = max(maxi,t[i][j]);
            return t[i][j];
            
        }else{
            return t[i][j]='0';
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> t(n,vector<int>(m,-1));
        solve(matrix,0,0,maxi,t);
        // memset(t,-1,sizeof(t));

        return maxi ;
    }
};


// table



