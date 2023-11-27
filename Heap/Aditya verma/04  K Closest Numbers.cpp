https://leetcode.com/problems/find-k-closest-elements/
658. Find K Closest Elements


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxi;
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++){
            
            maxi.push({abs(arr[i]-x),arr[i]});
            
            if(maxi.size()> k){
                maxi.pop();
            }
        }
        
        while(!maxi.empty()){

           ans.push_back(maxi.top().second);
            maxi.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
