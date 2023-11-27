

#include<iostream>
#include<queue>
using namespace std;


int countNode(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1+ countNode(root -> left) + countNode(root -> right);
    return ans;
}


bool isCBT(struct Node* root, int index , int count){
    if(root == NULL){
        return true;
    }

    if(index >= count){
        return false;
    }else{
        bool left = isCBT(root -> left, 2*index+1, count);
        bool right = isCBT(root -> right, 2*index+2, count);
        return (left && right);
    }
}

bool isMaxOrder(struct Node* root){
    if(root -> left == NULL && root -> right == NULL){
        return true;
    }
    if(root -> right == NULL){
        return (root->data > root->left->data);
    }else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return(left && right && 
        (root->data > root->left ->data && root->data > root->right ->data));
    }
}

bool isHeap(struct Node* root){
    int index = 0;
    int totleCount = countNode(root);

    if(isCBT(root, index, totleCount) && isMaxOrder(root)){
        return true;
    } else{
        return false;
    }
}




int main(){
    heap h;
    h.insert(20);
    h.insert(30);
    h.insert(15);
    h.insert(25);
    h.insert(29);
    h.insert(22);
    h.insert(24);


    // priority_queue
     
    //  maxheap
    priority_queue<int> maxheap;

    // max heap

    priority_queue<int, vector<int> , greater <int>> minheap;


    return 0;
}
// timeComplexity O(log n)