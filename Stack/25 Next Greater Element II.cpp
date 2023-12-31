503. Next Greater Element II
https://leetcode.com/problems/next-greater-element-ii/




class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        stack<int> s;
        
        for(int i = n-1;i>=0;i--){
            s.push(nums[i]);
        }
        
        for(int i =n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
            
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};