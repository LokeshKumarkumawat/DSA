class Solution {
public:
    
    bool check(vector<int> bash,vector<int> newBox){
        if(newBox[0]<= bash[0] && newBox[1] <= bash[1] && newBox[2] <= bash[2]){
            return true;
        }else{
            return false;
        }
    }
    
    int solve(int n,vector<vector<int>>& a){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int crr = n-1;crr>=0; crr--){
            for(int prev = crr-1; prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || check(a[crr],a[prev])){
                    take = a[crr][2] + nextRow[crr+1];
                }
                
                //exclude
                int notTake = 0 + nextRow[prev+1];
                currRow[prev+1] =  max(take,notTake);
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
        
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a: cuboids){
            sort(a.begin(),a.end());
        }
        
        sort(cuboids.begin(),cuboids.end());
        
        return solve(cuboids.size(),cuboids);
    }
};