// #include<bits/stdc++.h>

// struct datatype{
//     int val;
//     int arr;
//     int pos;
//     datatype(int v, int a, int p){
//         val = v;
//         pos =p;
//         arr =a;
//     }
    
// };

// struct cmpare{
//   bool operator()(datatype & d1 , datatype & d2){
//       return d1.val>d2.val;
//   }
    
// };


// vector<int> mergeKSortedArrays(vector<vector<int>>array, int k)
// {
//     // Write your code here. 
//     priority_queue<datatype, vector<datatype>,cmpare> minHeap; //minheap
//     for(int i = 0 ;i<k ;i++){
//         pq.push({array[i][0],i,0});
//     }
//     vector<int>ans;
//     while(!pq.empty()){
//         auto d = pq.top();
//         pq.pop();
//         int val = d.val;
//         int arr = d.arr;
//         int pos = d.pos;
//         ans.push_back(val);
//         if(pos!= array[arr].size()-1){
//             pq.push({array[arr][pos+1],arr,pos+1});
//         }
//     }
//     return ans;
// }








#include<bits/stdc++.h>

struct node{
    int data;
    int i;
    int j;
    node(int a, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
    
};

class cmpare{
  bool operator()(node* a ,node* b){
      return a->data > b->data;
  }
    
};


vector<int> mergeKSortedArrays(vector<vector<int>>array, int k)
{
    
    priority_queue<node*, vector<node*>,cmpare> minHeap; //minheap

    for(int i = 0 ;i<k ;i++){
        node* tem = new node(arr[i][0],i, 0);
        minHeap.push(tem);
    }
    
    vector<int>ans;


    while(minHeap.size() > 0){
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tem->i;
        int j = tem->j;

        if(j+1 < array[i].size()){
            node* next  = new node(array[i][j+1], i , j = j+1);
            minHeap.push(next);

        }
    }
    return ans;
}