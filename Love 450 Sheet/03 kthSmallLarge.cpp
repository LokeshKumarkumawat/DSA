#include<algorithm>
vector<int> kthSmallLarge(vector<int> &v, int n, int k)
{
	// Write your code here.
    sort(v.begin(), v.end());
    
    int kLarge , kSmall;
    vector<int>ans;
    kLarge = v[k-1];
    kSmall = v[n-k];
    ans.push_back(kLarge);
    ans.push_back(kSmall);
    return ans;
}