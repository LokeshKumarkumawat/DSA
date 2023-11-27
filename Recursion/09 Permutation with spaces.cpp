#include<bits/stdc++.h>
using namespace std;

vector<string> subset(string ip, string op, vector<string> &ans){
    //Base Condition
    if(ip.size()==0){
        ans.push_back(op);
        return ans;
    }
    //Hypothesis
    string op1=op;
    string op2=op;
    op2.push_back('_');
    op2.push_back(ip[0]);
    op1.push_back(ip[0]);
    ip.erase(ip.begin()+0); 
    //Induction
    subset(ip,op1,ans);
    subset(ip,op2,ans);
    return ans;
}

int main()
{
    string ip;
    cin>>ip;
    string op="";
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    vector<string> ans;
    subset(ip,op,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}