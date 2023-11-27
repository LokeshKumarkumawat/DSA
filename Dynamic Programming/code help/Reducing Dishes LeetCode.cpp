// tle\\

class Solution {
public:
    int solve(vector<int> &sat, int index,int time){
        // bash
        if(index == sat.size()){
            return 0;
        }
        
        int in =sat[index] *(time+1) +solve(sat,index+1,time+1);
        int ex = 0 + solve(sat,index+1,time);
        
        int ans = max(in,ex);
        return ans;
        
    }
    
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        return solve(sat,0,0);  
    }
};

////////////////////////////////////////////////////////////////////////// //////////////
//memo //////////////////////////////////

class Solution {
public:
    int solve(vector<int> &sat, int index,int time, vector<vector<int>> &t){
        // bash
        if(index == sat.size()){
            return 0;
        }
        
        if(t[index][time] != -1){
            return t[index][time];
        }
        
        int in =sat[index] *(time+1) +solve(sat,index+1,time+1,t);
        int ex = 0 + solve(sat,index+1,time,t);
        
        t[index][time] = max(in,ex);
        return t[index][time];
        
    }
    
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>t (n+1,vector<int>(n+1,-1));
        return solve(sat,0,0,t);  
    }
};

/////////////////////
//table

class Solution {
public:
    int solve(vector<int> &sat, int index,int time){
        // bash
        int n = sat.size();
        vector<vector<int>>t (n+1,vector<int>(n+1,0));
        
        
        for(int index = n-1; index>=0;index--){
            for(int time = index; time>=0;time--){
                
                int in =sat[index] *(time+1) +t[index+1][time+1];
                int ex = 0 + t[index+1][time];
                t[index][time] = max(in,ex);
            }
        }

        return t[index][time];
        
    }
    
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        return solve(sat,0,0);  
    }
};