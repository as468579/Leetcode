// enum, 2D array, 

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length());
        
        for(int i=0; i<s.length(); ++i){
            vector<bool>tmp (s.length(), true);
            dp[i] = tmp;
        }
        
        for(int j=1; j<dp.size(); ++j){
            for(int i=0; i<j ; ++i){
                dp[i][j] = (dp[i+1][j-1]) & (s[i] == s[j]);
            }
        }
        
        int s_col, i, j;
        bool success = false;
        for(s_col=dp.size()-1; s_col>=0; --s_col){
            i = 0; 
            j = s_col;
            while(j < dp.size()){
                if(dp[i][j]){
                    success = true;
                    break;
                }
                i = i+1;
                j = j+1;
            }
            if(success){ break; }
        }
        
        string res = "";
        for(; i<=j; i++){
            res = s[i] + res;
        }
        return res;
    }
};