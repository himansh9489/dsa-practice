#include <bits/stdc++.h>
using namespace std;
// Memoization (top - down) approach
// tc -> O(n)
// sc -> O(n) + O(n)
int fun(int n, vector<int> &dp) {
    if(n <= 1) return n;
    
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = fun(n-1, dp) + fun(n-2, dp);
}
int main(){
    // finding Fibonacci number 
    int n;
    cin>> n;
    vector<int> dp(n+1, -1);
    
    // cout<< fun(n, dp);
    
    
    // Tabulation (bottom - up) approach
    // tc -> O(n)
    // sc -> O(n)
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i = 2; i <= n; i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout<< dp[n];

    // Space Optimization
    // tc -> O(n)
    // sc -> O(1)
    int prev = 1, prev2 = 0;
    for(int i = 2; i <= n; i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout<<prev;
}