4 Sort a K Sorted Array | Sort Nearly Sorted Array






class Solution {
public:
    int solve(vector<int>& nums, int k) {
		vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> minh;
        int n= nums.size();
        for (int i=0;i<n;i++)
        {
            minh.push(nums[i]);

            if (minh.size()>k){
				v.push_back(minh.top());
                minh.pop();
            }
                    
        }
        return ans;
        
    }
};