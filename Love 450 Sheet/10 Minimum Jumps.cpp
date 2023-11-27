int minimumJumps(vector<int> &arr, int n){
    int jump =0;
    int mn =0; 
    int mx =0; 
   
   for(int i =0;i<n-1;i++){  
        if(i+arr[i] > mx ){
            mx = i+arr[i];
        }   

        if(i == mn ){       
            jump++;        
            mn = mx;    
        }    

        if(i == mx){
            return -1;
        }  
    }   
    return jump;  

 }