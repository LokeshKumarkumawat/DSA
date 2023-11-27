// You must implement a solution with O(1) time complexity for each function.
// aditya verma

https://leetcode.com/problems/min-stack/
155. Min Stack

// 2x-min_element
//mistek
class MinStack {
public:
    int min_element;
    stack<int> s;
    
    MinStack() {
        
    }

    
    void push(int x) {
        if(s.size() == 0){
            s.push(x);
            min_element = x;
        }else{
            if(x>=min_element){
                s.push(x);
            }else if(x<min_element){
                s.push((2*x)-min_element);
                min_element = x;
            }
        }
    }
    
    void pop() {
        if(s.size() == 0){
            return -1;
        }else{
            if(s.top() >= min_element){
                s.pop();
            }else if(s.top()<min_element){
                min_element = (2*min_element)-s.top();
                s.pop();
            }
        }

    }
    
    int top() {
        if(s.size() == 0{){
            return -1;
        }
        else{
            if(s.top() >= min_element){
                return s.top();
            }else if(s.top() < min_element){
                return min_element;
            }
        }
    }
    
    int getMin() {
        if(s.size() == 0){
            return -1;
        }
        return min_element;
    }
};

//leetcode

class MinStack {
    
private:
    stack<long long int> s;
    long long int minele=1e12;;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minele=val;
        }
        else{
            if(val>=minele)
               {s.push(val);}
            else if(val< minele){
                s.push(2LL*val-minele);
                minele=val;
            }
        }
    }
    
    void pop() {
        if(s.empty())
        {return;}
        else{
            if(s.top()>=minele)
            {  s.pop();}
            else if(s.top()< minele){
                minele=2*minele-s.top();
                s.pop();
            }
        }

    }
    
    int top() {
        if(s.empty())
        {return -1;}
        else{
            if(s.top()>=minele)
            {return s.top();}
            else if(s.top()< minele)
            { return minele;}
        }
        return s.top();
    }
    
    int getMin() {
        if(s.empty())
        {return -1;}
        return minele;
    }
};
