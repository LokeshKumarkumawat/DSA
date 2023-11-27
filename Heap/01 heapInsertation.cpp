#include<iostream>
using namespace std;

  

    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index < 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return ;
            }
        }
    }

    void print(){
        for(int i = 0; i<=size; i++){
            cout<<arr[i]<<endl;
        }
    }

};

int main(){
    heap h;
    h.insert(20);
    h.insert(30);
    h.insert(15);
    h.insert(25);
    h.insert(29);
    h.insert(22);
    h.insert(24);

    return 0;
}
// timeComplexity O(log n)