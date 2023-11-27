https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/





class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<int>st;
        int len = s.length();
        int count = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else
            {
                if(s[i] == ')' && st.empty() == false)
                    st.pop();
                else
                    count++;
            }
                
        }
        return st.empty() ? count : count+st.size();
    }
};