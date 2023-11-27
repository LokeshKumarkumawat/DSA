#define MOD 1000000007

long long int countDerangements(int n){
    // bash
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    int ans = (((n-1)%MOD) * 
              ((countDerangements(n-1)%MOD) +
              (countDerangements(n-2)%MOD))%MOD);



    return ans;
}

// ////////////////////////////////////////////////////////////////////////
// MEMOIZATION

#define MOD 1000000007

long long int solve(int n,vector<long long int> & dp){
    // bash
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }


    dp[n]= (((n-1)%MOD) * 
              ((countDerangements(n-1)%MOD) +
              (countDerangements(n-2)%MOD))%MOD);



    return dp[n];
}

long long int countDerangements(int n){

    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
}


///////////////////////////////////
// table

#define MOD 1000000007

long long int solve(int n){
    vector<long long int> dp(n+1,0);
    // bash
    dp[1] =0;
    dp[2] =1 ;

    for(int i=3;i<=n;i++){
        long long int first = dp[i-1]%MOD; 
        long long int second = dp[i-2]%MOD; 
        long long int sum = (first + second)%MOD;

        long long int ans = ((i-1)* sum)%MOD; 
        dp[i] = ans; 

    }

    return dp[n];



}

long long int countDerangements(int n){
    return solveTab(n);
}