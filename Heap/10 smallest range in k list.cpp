#include<queue>
#include<limits.h>
class node{
    public:
        int data;
        int row;
        int col;
    node(int data,int row,int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compar{
    public:
    bool operator()(node *a,node *b)
    {
        return a->data>b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<node *,vector<node *>,compar> pq;
    
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<k;i++)
    {
        int ele = a[i][0];
        pq.push(new node(ele,i,0));
        maxi = max(ele,maxi);
        mini = min(ele,mini);
    }
    int start = mini;
    int end = maxi;
    
    while(!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();
        mini = temp->data;
        
        if(maxi-mini < end-start)
        {
            end = maxi;
            start = mini;
        }
        
        if(temp->col+1<n)
        {
            maxi = max(a[temp->row][temp->col+1],maxi);
            pq.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else
        {
            break;
        }
    }
    
    return end-start+1;
}


