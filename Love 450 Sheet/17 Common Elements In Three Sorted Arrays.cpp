bool binary_search(vector<int> &arr,int tar){
    
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)>>1;
        if(arr[mid]==tar)return true;
        
        else if(arr[mid]>tar)high = mid-1;
        else low = mid+1;
    }
    return false;
}

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
   vector<int> ans;    
    for(int i=0;i<a.size();i++){
        
        if(i !=0 && a[i]==a[i-1])continue;//avoiding duplicate
        
        if(  binary_search(b,a[i]) && binary_search(c,a[i]) )ans.push_back(a[i]);
    }
    return ans;

}