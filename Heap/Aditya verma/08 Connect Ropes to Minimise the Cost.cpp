class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int val;
        priority_queue<int,vector<int>,greater<int>> minh;
        int n= nums.size();
        for (int i=0;i<n;i++)
        {
            minh.push(nums[i]);
        }

        int cost = 0;

        while(minh.size()>=2){
            int first = minh.top();
            minh.pop();
            int second = minh.top();
            minh.pop();

           
            cost += first+second;
            minh.push(first+second);
        }
        return cost;
        
    }
};