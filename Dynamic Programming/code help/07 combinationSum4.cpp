class Solution {
public:
    
    int solve(vector<int> &nums, int n, int target){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        int ans =0;
        
        for(int i= 0;i<n;i++){
            ans += solve(nums, n ,target-nums[i]); 
        }
        
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
         int n = nums.size();        
         return solve(nums, n,target);
    }
};


//memoization
class Solution {
public:
    
    int solve(vector<int> &nums, int n, int target, vector<int> &dp){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        
        if(dp[target] != -1){
            return dp[target]; 
        }
        
        int ans =0;
        
        for(int i= 0;i<n;i++){
            ans += solve(nums, n ,target-nums[i], dp); 
        }
        
        dp[target] = ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
         int n = nums.size();    
         vector<int> dp(target+1,-1);
         return solve(nums, n,target,dp);
    }
};

// leetcode

class Solution {
public:
    
    int solve(vector<int> &nums, int n, int target){
        
        vector<long long> dp(target+1,0);
        
        dp[0] = 1;
        
        for(int i= 1;i<=target;i++){
            int ways = 0;
            for(int j=0;j<n;j++){
                
                if(i-nums[j]>=0){
                    ways += dp[i-nums[j]]; 
                }
            }
            dp[i] = ways;
            
        }
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
         int n = nums.size();    
         return solve(nums, n,target);
    }
};



//ninga


class Solution {
public:
    
    int solve(vector<int> &nums, int n, int target){
        
        vector<int> dp(target+1,0);
        
        dp[0] = 1;
        
        for(int i= 1;i<=target;i++){
            for(int j=0;j<n;j++){
                
                if(i-nums[j]>=0){
                    dp[i] += dp[i-nums[j]]; 
                }
            }
          
            
        }
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
         int n = nums.size();    
         return solve(nums, n,target);
    }
};