#include<bits/stdc++.h>
using namespace std;
int kthGrammar(int n, int k) {
        if(n==1 && k==1)
            return 0;
        int mid=pow(2,n-1)/2;
        if(k<=mid)
        {
            return kthGrammar(n-1,k);
        }
        return !kthGrammar(n-1,k-mid);
}
int main(){
     int n,k;
     cin>>n>>k;
     cout<<kthGrammar(n,k);
}


//leet code 
https://leetcode.com/problems/k-th-symbol-in-grammar/




Q2.
1545. Find Kth Bit in Nth Binary String
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution
{
	public:
		char findKthBit(int n, int k)
		{
			if (n == 1 && k == 1)
			{
				return '0';
			}

			int len = pow(2, n);
			int mid = len / 2;

			if (k == mid)
			{
				return '1';
			}
			else if (k < mid)
			{
				char ans2 = findKthBit(n - 1, k);//ans glt aa skta h ye nhi krne pr XX 'findKthBit(n - 1, k)'
				return ans2;
			}
			else
			{
				char ans = findKthBit(n - 1, len - k);
				if (ans == '0')
				{
					return '1';
				}
				else
				{
					return '0';
				}
			}
		}
};