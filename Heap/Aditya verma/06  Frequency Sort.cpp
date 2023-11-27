1636. Sort Array by Increasing Frequency

https://leetcode.com/problems/sort-array-by-increasing-frequency/

class compare{
  public:
    bool operator() (pair<int,int>& a, pair<int,int>& b) {
        if(a.first < b.first)
            return false;
        else if(a.first > b.first)
            return true;
        else{
            if(a.second > b.second)
                return false;
            else 
                return true;
        }
    }
};





class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int>umap;
        
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>minh;
        
        for(auto i = umap.begin(); i!=umap.end();i++){
            minh.push({i->second,i->first});
        }
        
        vector<int> ans;
        
        while(!minh.empty()){

            int fre = minh.top().first;
            int ele  = minh.top().second;

            for(int i=1;i<=fre;i++){
                ans.push_back(ele);
            }
            minh.pop();
        }
        
        // sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};