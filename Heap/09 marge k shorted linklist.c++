#include<queue>

class compare{

   public:

    bool operator()(Node<int>* a,Node<int>* b){

        return a->data > b->data;

    }

};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)

{

   // Write your code here.

   priority_queue<Node<int> *,vector<Node<int> *>,compare> minheap;

    int k=listArray.size();

     

     if(k==0){
        return NULL;
     }
         

      for(int i=0; i<k; i++){
          if(listArray[i]!=NULL){
              minheap.push(listArray[i]);
          }

      }

   Node<int>* head=NULL;

   Node<int>* tail=NULL;

   

    while(minheap.size()>0){

        Node<int>* top=minheap.top();
        minheap.pop();

        if(top->next!=NULL){
            minheap.push(top->next);
        }

        if(head== NULL){
            head=top;
            tail=top;
        }
        else{
            tail->next=top;
            tail=top;
        }
    }

   return head;

};


// TC => O(k log k) + O(n*k log k) =  O(nk log k)
// SC => O(k)