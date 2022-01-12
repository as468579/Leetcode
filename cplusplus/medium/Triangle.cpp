class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp(triangle.size());
        for(auto &v: dp){
            v = vector<int>(triangle.size(), 100000);
        }

        dp[0][0] = triangle[0][0];
        for(int i=1; i<triangle.size(); ++i){
            for(int j=0; j<=i; ++j){
                if(j){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
            }
        }
        
        
        int min = INT_MAX;
        for(int j=0; j<triangle.size(); ++j){
            if(dp[triangle.size()-1][j] < min){
                min = dp[triangle.size()-1][j];
            }
        }

        return min;
        
    }
};