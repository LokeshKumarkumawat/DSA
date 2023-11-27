vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) // foirst col second row
{
    // Write your code here.
    vector<vector<int>> ans;
    int n=intervals.size();
    
    sort(intervals.begin(),intervals.end());
    
    for(int i=0;i<n;i++){
        if(ans.empty()){
            ans.push_back(intervals[0]);
        }
        else{
            vector<int>&v=ans.back(); // 1,4 sida push hoga
            int temp=v[1];
            if(intervals[i][0]<=temp){//1 3
                v[1]=max(temp,intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);//2 4
            }
        }
    }
   
    return ans;
}








vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    int  n=intervals.size();
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        
        if(ans.back()[1]>=intervals[i][0])
        {
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            cout<<first<<i<<ans.back()[1]<<endl;
        }else{
            ans.push_back(intervals[i]);
        }
 

    }
    return ans;
}


