#include<bits/stdc++.h>
using namespace std;

    void solve(int one, int zero, int n, string op, vector<string>& v){
        // base condition
        if(n==0){ // when we reach N=0, thn ouput would be one of the answers
            v.push_back(op);
            return;
        }


        
        // 1 can be chosen at any moment, provided N>0
        if(n>0){
                string op1= op;
                op1.push_back('1');
                solve(one +1, zero,n-1,op1,v);

        }
        // if count1 > count0, then choosing 0 here is safe
        if(one > zero){
            string op3 = op;
            op3.push_back('0');
            solve(one, zero+1, n-1,op3,v);
        }
        
        
    }

    int main(){

        int n;
        cin>> n ;
        string op = "";
        int one = 0;
        int zero = 0;
        vector<string> v;
        solve(one, zero,n,op, v);


    }