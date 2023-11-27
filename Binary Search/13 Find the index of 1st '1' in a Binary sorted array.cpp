class Solution{
  public:
  int firstIndex(int a[], int n)
  {
    int start =0;
    int end= n-1;
    while (start<=end){
      int mid = start+(end-start)/2;
      if (a[mid]==1)
      {
        if (a[mid-1]==1) // when the previous is also 1 then check in the right side 
        {
          end=mid-1;
        }
        else 
          return mid;
      }
      else 
        if (a[mid]==0)
        {
          start=mid+1;
        }
    } // close of while loop 
    return -1;
  }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        if(target>nums[nums.size()-1)]){
            return nums.size()-1;
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid]<target){
                s= mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
};