// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1#

class Solution{
  public:
  int findFloor(vector<long long> v, long long n, long long x){
    int start=0;
    int end=n-1;
    int res=-1;
    while (start<=end){
      int mid= start+(end-start)/2;
      if (x==v[mid])
        return mid;
      else if(x>v[mid])
       // continue biniry search on left size of the array
        end= mid-1;
      else 
      {
        // store candidate in res and continue BS in right side
        res=mid; 
        start=mid+1;
      }
    }
    // at last return greatest element smaller then x
    return res; 
  }
};
