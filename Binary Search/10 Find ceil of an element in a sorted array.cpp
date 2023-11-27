class Solution{
  public:
  int findFloor(vector<long long> v, long long n, long long x){
    int start=0;
    int end=n-1;
    int res=-1;
    while (start<=end){
      int mid= start+(end-start)/2;
      if (x==v[mid])
        return v[mid];
      else if(x<v[mid])
      {
        // store candidate in res and continue BS in reft side 
        // to find smallest element greater then x
        res=v[mid]; 
        // then set end at the index mid-1 
        end= mid-1;  
      }
      else 
      {
        // continue biniry search on right size of the array
        start=mid+1; 
      }
    }
    // at last return smallest element greater then x
    return res; 
  }
};
