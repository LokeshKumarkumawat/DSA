// Power of Two

https://leetcode.com/problems/power-of-two/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base Cases
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        
        // Check remainder is 0 or not when divided by 3, and recursion call.
        return (n % 2 == 0) && (isPowerOfTwo(n/2));
    }
};
