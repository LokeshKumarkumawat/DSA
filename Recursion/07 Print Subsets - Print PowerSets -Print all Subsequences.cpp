
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		         string out = "";
                 vector<string>ans;
                 solve(s,out,ans);
                sort(ans.begin(),ans.end());
                ans.erase(ans.begin()+0);
                return ans;
		    
        };

        void solve(string in, string &out, vector<string>&ans) {
           if(in.length()==0) {
             ans.push_back(out);
               return;
           }
           string op1 = out;
           string op2 = out;
           
            op2.push_back(in[0]);
            in.erase(in.begin() + 0);
            
            
           solve(in,op1,ans);
           solve(in,op2,ans);
           
       }
       

        };

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends





//Aditya verma

#include<bits/stdc++.h>
using namespace std;
void solve(string in, string &op) {
	if (in.length() == 0) {
		cout << op << " ";
		return;
	}
	//picking 
    string op1 = op;
    string op2 = op;
    
    op2.push_back(in[0]);
    in.erase(in.begin() + 0);

	solve(in, op1);
	solve(in,op2);
}
int main() {
	string in = "abc";
	string op = "";

	cout<<"All possible subsequences are: "<<endl;
	solve(in, op);
}


// 78. Subsets unique element only
class Solution {
public:
    
    void solve(vector<int>in,vector<int>&op,vector<vector<int>> &ans ){
        if(in.size() == 0){
            ans.push_back(op);
            return;
        }
        
        vector<int>op1 =op;
        vector<int>op2 = op;
        
        op2.push_back(in[0]);
        in.erase(in.begin()+0);
        
        solve(in,op1,ans);
        solve(in,op2,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& in) {
        vector<int>op;
        vector<vector<int>> ans;
        
        solve(in,op,ans);
        return ans;
    }
};

// 90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set)

class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    
    void solve(vector<int>in, vector<int>op){
        
        if(in.size() == 0){
            
            if(s.find(op) == s.end()){
                s.insert(op);
                ans.push_back(op);   
            }
            
            return;
        }
        
        vector<int>op1 = op;
        vector<int> op2 = op;
        
        op1.push_back(in[0]);
        in.erase(in.begin() + 0);
        
        solve(in, op1);
        solve(in, op2);   
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& in) {
        
        sort(in.begin(), in.end());
        vector<int>op;
        
        solve(in, op);
        return ans; 
    }
};








