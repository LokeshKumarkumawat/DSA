int sumOfMaxMin(int arr[], int n){
	// Write your code here.
    int mn = arr[0];
    int mx = arr[0];
    for(int i = 1; i<n;i++){
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    int ans = mn+mx; 
    return ans;
}


