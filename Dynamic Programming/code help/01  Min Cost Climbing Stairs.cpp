// leetcode

//memoization
class Solution {
public:
    
    int solve(vector<int>& cost,int n,vector<int> &dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){ 
            return cost[1];
        }
        if(dp[n] != -1 ){
            return dp[n];
        }
        
        
        dp[n] = cost[n] + min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int ans = min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        return ans;                               
        
    }
};


class Solution {
public:
    
    int solve(vector<int>& cost,int n){
        vector<int> dp(n+1);

        dp[0] = cost[0]; //=>3
        dp[1] = cost[1]; // => 3

        //n=>3
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        // n=>3
        return min(dp[n-1], dp[n-2]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // n=>3
        return solve(cost,n);
                           
        
    }
};

https://leetcode.com/problems/min-cost-climbing-stairs/



class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int n = c.size();
        int dp[n+1]; //dp[i] denote min cost to reach i
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
           dp[i]= min(c[i-1]+dp[i-1], c[i-2]+dp[i-2]);
        }
        return dp[n];
    }
}; 


// or



class Solution {
public:
    int solve(vector<int> &cost,int n){
        vector<int>dp(n,0);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2;i<n;i++){
            dp[i] = cost[i] +  min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
};