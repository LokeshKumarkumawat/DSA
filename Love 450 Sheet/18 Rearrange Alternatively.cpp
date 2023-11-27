#include<bits/stdc++.h>
using namespace std;
    // Write your code here.
    void rearrange(vector<int> &v)
    {
        int n = v.size(), i = 0, c = 0;
        while (i < n)
        {
            if (v[i] < 0 && c % 2 == 0)
            {
                int temp = v[i];
                v[i] = v[c];
                v[c] = temp;
                c++;

                cout<<"first>"<<i<<endl;
               
            }
            else if (v[i] >= 0 && c % 2 == 1)
            {
                int temp = v[i];
                v[i] = v[c];
                v[c] = temp;
                c++;
                cout<<"secon>"<<i<<endl;
                
            }
            else{
                cout<<"third>"<<i<<endl;
                
                i++;
                
            }
                
        }
    };


int main(){
    vector<int>v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(-5);
    rearrange(v);
    return 0;
}




