#include<iostream>
#include<algorithm>
using namespace std;
// 0(n2logn) - (n2)
int getkthLargest(vector<int> &arr, int k){
    vector<int> sumStore;

    int n = arr.size();

    
    for(int i=0; i<n;i++){

        int sum = 0;

        for(int j=0; j<n;j++){
            sum  += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size()-k];
}



int main(){


}

// O(log n2)  -> O(log k)

int getkthLargest(vector<int> &arr, int k){
    priority_queue<int , vector<int>, greater<int> > mini;

    int n = arr.size();

    for(int i=0; i<n; i++){
        int sum = 0;

        for(int j=1; j<n;j++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
        
    }


    return mini.top();


}



int main(){


}