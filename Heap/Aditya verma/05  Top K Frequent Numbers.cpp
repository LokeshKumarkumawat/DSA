https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>umap;
        
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        
        for(auto i = umap.begin(); i!=umap.end();i++){
            minh.push({i->second,i->first});
            
            if(minh.size()>k){
                minh.pop();
            }
        }
        
        vector<int> ans;
        
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        
        return ans;
        
    }
};