// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
int i=1;
for(int j=1; j<=n; j++) i*=j;
return i;
}

void sol(int n, int k, string& x, vector<int>& v){
    if(n==0) return;
    int f=fact(n-1), y=f, c=1;
    while(y<k){
        c++;
        y=f*c;
    }
    x+=to_string(v[c-1]);
    vector<int>::iterator it;
    it=v.begin()+c-1;
    v.erase(it);
    sol(n-1, k-y+f, x, v);
}



void getPermutation(int n, int k) {
    string op="";
    vector<int> v;
    for(int i=1; i<=n; i++) v.push_back(i);
    sol(n, k, op, v);

    for(int i=0;i<n;i++){
        cout<<op[i];
    }
   
}



int main()
{
    // string ip;
    // cin>>ip;
    // string op="";
    // op.push_back(ip[0]);
    // ip.erase(ip.begin()+0);
    // vector<string> ans;


    int n;
    int k;

    cin>>n;

    cin>>k;




    getPermutation(n,k);

    return 0;
}