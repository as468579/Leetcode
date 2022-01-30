class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        // 0: first charater
        // 1: leading bit of second character
        // 2: ending  bit of second character
        vector<char>dp (bits.size(), 0);
        
        dp[0] = bits[0];
        for(int i=1; i<bits.size(); ++i){
            if(dp[i-1] == 1){ dp[i] = 2; }
            else{ dp[i] = bits[i]; }
        }
        return (!dp[dp.size()-1]);
    }
};