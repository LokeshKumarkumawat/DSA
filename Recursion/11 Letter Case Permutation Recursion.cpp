#include<bits/stdc++.h>
using namespace std;

vector<string> subset(string ip, string op, vector<string> &ans){
    //Base Condition
    if(ip.size()==0){
        ans.push_back(op);
        return ans;
    }
    //Hypothesis


    if(isalpha(ip[0])){
        string op1=op;
        string op2=op;

        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));

        ip.erase(ip.begin()+0);

        subset(ip,op1,ans);
        subset(ip,op2,ans);


    }else{ // Digit Valve
        string op1=op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);

        subset(ip,op1,ans);
    }

    
    
    //Induction

    return ans;
}

int main()
{
    string ip;
    cin>>ip;
    string op="";
    vector<string> ans;
    subset(ip,op,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}