class LC22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open = n;
        int close = n;
        string op="";
        generate(open , close , op, v);
        return v;
    }
private:
    void generate(int open, int close, string op, vector<string>& v) {
        if (open == 0 && close == 0) {
            v.push_back(op);
            return;
        } 
        
        if(open != 0 ){
            string op1 = op;
            op1.push_back('(');
            generate(open-1 , close , op1, v);
        }
        if(close>open){
            string op2 = op;
            op2.push_back(')');
            generate(open, close-1, op2,v);

        }
        return;
        

    }
};



