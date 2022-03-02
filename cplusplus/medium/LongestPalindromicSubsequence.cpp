class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> LPS(s.length()+1, vector<int>(s.length()+1, 0));
        
        for(int j=1; j<=s.length(); ++j){
            for(int i=j; i>0; --i){
                if(i == j){ 
                    LPS[i][j] = 1; 
                }else if(s[i-1] == s[j-1]){
                    LPS[i][j] = LPS[i+1][j-1] + 2;
                }else{
                    LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1]);
                }
            }
        }

        return LPS[1][s.length()];
    }
};



// if(s[i] == s[j]): LPS[i][j] = LPS[i+1][j-1] + 2;
// else: LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1]);