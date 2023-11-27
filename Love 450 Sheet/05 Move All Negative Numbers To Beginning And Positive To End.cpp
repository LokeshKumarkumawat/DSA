vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Write your code here.
   int size=nums.size();
   int j=0;
   for(int i=0;i<size;i++){
       if(nums[i]<0 ){
           if(i!=j)
           {
           swap(nums[i],nums[j]);
           }
           j++;
       }
   }
   return nums;
}
#include<algorithm>
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Write your code here.
    sort(nums.begin(),nums.end());
    return nums;
}