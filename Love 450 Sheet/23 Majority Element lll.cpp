vector<int> countTheNumber(vector<int> &arr, int n, int k) {
    // Write your code here.
    
    vector<int> ans;
    
    int limit = n/k;
    unordered_map<int, int> count;
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    for(auto it: count){
        if(it.second >= limit){
            ans.push_back(it.first);
        }
    }
    return ans;
}