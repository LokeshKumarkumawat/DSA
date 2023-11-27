

42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ml[n];
        int mr[n];
        //fill left array
        ml[0]= height[0];
        for (int i = 1; i < n; i++)
        {
            ml[i] = max(ml[i-1], height[i]);
        }
        // fill right array
        mr[n-1] = height[n-1];
        for (int j = n - 2; j >= 0; j--)
        {
            mr[j] = max(mr[j+1], height[j]);
        }
        
        int wtr[n];
        for (int i = 0; i < n; i++)
        {
            wtr[i] = min(ml[i], mr[i]) - height[i];
        }
        
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            sum = sum+ wtr[k];
        }
        
        return sum;
    }
};