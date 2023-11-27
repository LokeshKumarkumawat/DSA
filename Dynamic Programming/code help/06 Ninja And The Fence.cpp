// recursion
#define MOD 1000000007
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD) * (b%MOD) )%MOD;
}
int solve(int n,int k){
//     bash
    if(n==1){
        return k;
    }
    if(n==2){
        // same=k+diff=k*k-1
        return add(k,mul(k,k-1));
    }
    //same = solve(n-2) *k-1;
    //+
    //solve(n-1)*k-1   
    int ans = add(mul(solve(n-2,k), k-1), mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}

//! /////////////////////////////////////////////////////////////
// memoi

#define MOD 1000000007


int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1ll * (b%MOD) )%MOD;
}

int solve(int n,int k,vector<int> &dp){
//     bash
    if(n==1){
        return k;
    }
    if(n==2){
        // same=k+diff=k*k-1
        return add(k,mul(k,k-1));
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    //same = solve(n-2) *k-1;
    //+
    //solve(n-1)*k-1
    
    dp[n] = add(mul(solve(n-2,k,dp), k-1), mul(solve(n-1,k,dp),k-1));
    return dp[n];
}


int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}


//* ////////////////////////////////

// table

#define MOD 1000000007


int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1ll * (b%MOD) )%MOD;
}

int solve(int n,int k){
//     bash
    vector<int> dp(n+1,0);
    dp[1] =k;
    dp[2] = add(k,mul(k,k-1));
    
    for(int i = 3;i<=n;i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}


int numberOfWays(int n, int k) {
    // Write your code here.
    
    return solve(n,k);
}
