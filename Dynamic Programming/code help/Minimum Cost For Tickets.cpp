// tle

class Solution {
public:
    
    int solve(int n, vector<int> &days,vector<int>& costs, int index){
        if(index>=n){
            return 0;
        }
        
        //onr day
        int option1 = costs[0]+ solve(n,days,costs,index+1);
        int i;
        //7 day
        
        for(i = index;i<n && days[i]<days[index]+7;i++);
        
        int option2 = costs[1] +solve(n,days,costs,i);
        //30days
        
        for(i = index;i<n && days[i]<days[index]+30;i++);
        
        int option3 = costs[2] +solve(n,days,costs,i);
        
        return min(option1,min(option2,option3));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int n = days.size();
        return solve(n,days,costs,0);
    }
};


////////////

// 100%% acuracy
meomo
class Solution {
public:
    
    int solve(int n, vector<int> &days,vector<int>& costs, int index,vector<int> &dp){
        if(index>=n){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        //onr day
        int option1 = costs[0]+ solve(n,days,costs,index+1,dp);
        int i;
        //7 day
        
        for(i = index;i<n && days[i]<days[index]+7;i++);
        
        int option2 = costs[1] +solve(n,days,costs,i,dp);
        //30days
        
        for(i = index;i<n && days[i]<days[index]+30;i++);
        
        int option3 = costs[2] +solve(n,days,costs,i,dp);
        
        return dp[index] =  min(option1,min(option2,option3));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int n = days.size();
        
        vector<int> dp(n+1, -1);
        return solve(n,days,costs,0,dp);
    }
};




////////////////////////////////////////////////////////////////

// table
// 11% acuracy
class Solution
{
	public:

		int solve(int n, vector<int> &days, vector<int> &costs, int index)
		{
			vector<int> dp(n + 1, INT_MAX);

			dp[n] = 0;
			for (int k = n - 1; k >= 0; k--)
			{
				//one day
				int option1 = costs[0] + dp[k + 1];

				int i;
				//7 day
				for (i = index; i < n && days[i] < days[k] + 7; i++);
				int option2 = costs[1] + dp[i];

				//30days
				for (i = index; i < n && days[i] < days[k] + 30; i++);
				int option3 = costs[2] + dp[i];
				dp[k] = min(option1, min(option2, option3));
			}

			return dp[0];
		}

	int mincostTickets(vector<int> &days, vector<int> &costs)
	{
		int n = days.size();
		return solve(n, days, costs, 0);
	}
};