
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<triangle.size(); ++i){
            for(int j=0; j<=i; ++j){
                if(j && (j!=i)){
                    
                    triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
                }
                else if(j){
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                }
                else{
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                }
            }
        }
        
        
        int min_value = INT_MAX;
        for(int j=0; j<triangle.size(); ++j){
            min_value = min(min_value, triangle[triangle.size()-1][j]);
        }
        return min_value;
    }
};
/* Space Complexity: O(2n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> prev(triangle.size(), 100000);
        vector<int> curr(triangle.size(), 100000);

        prev[0] = triangle[0][0];
        for(int i=1; i<triangle.size(); ++i){
            for(int j=0; j<=i; ++j){
                if(j){
                    curr[j] = min(prev[j-1], prev[j]) + triangle[i][j];
                }
                else{
                    curr[j] = prev[j] + triangle[i][j];
                }
            }
            prev = curr;
        }
        
        if(curr[0] == 100000){ return prev[0]; }
        
        int min = INT_MAX;
        for(int j=0; j<triangle.size(); ++j){
            if(curr[j] < min){
                min = curr[j];
            }
        }
        return min;
    }
};
*/


/* Space Complexity: O(n^2)
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
*/