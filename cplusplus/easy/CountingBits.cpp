// class Solution {
// public:
    
//     vector<int> countBits(int n){
//         vector<int>dp(n+1, 0);
//         if(n == 0){ return dp; }
        
//         dp[1] = 1;
//         for(int i=2; i<n; i=i+2){
//             dp[i]   = dp[i>>1];
//             dp[i+1] = dp[i>>1]+1;
//         }
//         if(!(n&1)){ dp[n] = dp[n>>1]; }

//         return dp;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1, 0);
        for(int i=1; i<=n; ++i){
            dp[i] = dp[i&(i-1)] + 1;
        }
        return dp;
    }
};