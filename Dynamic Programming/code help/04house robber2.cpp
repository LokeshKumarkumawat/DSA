class Solution {
public:
    int solve(int n, vector<int> &nums)
    {
        if (n == 1)
            return nums[0];

        int prev1 = max(nums[0], nums[1]);
        int prev2 = nums[0];

        for (int i = 2; i < n; i++)
        {
            int val = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = val;
        }

        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1)
            return nums[0];

        vector<int> withFirst, withLast;

        withFirst.push_back(nums[0]);

        for (int i = 1; i < n - 1; i++)
        {
            int val = nums[i];
            withFirst.push_back(val);
            withLast.push_back(val);
        }

        // for (int i = 0; i < n - 1; i++)
        // {
        //     if(i !=n-1 ){
        //         first.push_back((nums[i]));
        //     }

        //     if(i!=0){
        //         second.push_back((nums[i]);)
        //     }


        // }


        

        withLast.push_back(nums[n - 1]);

        return max(solve(n - 1, withFirst), solve(n - 1, withLast));
    }
};