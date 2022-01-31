// s = "aab"
// j:   0 1 2  
// i: 0 t t f
// i: 1 t t f
// i: 2   t t

class Solution {
public:
    vector<vector<string>> backforward(string &s, vector<vector<bool>> &dp, int curr){
        
        if(map.count(curr)){ return map[curr]; }
        vector<vector<string>> ret;
        string tmp_s = "";
        if(curr == 0){
            tmp_s += s[0];
            ret.push_back(vector<string>(1, tmp_s));
            map[0] = ret;
            return ret; 
        }
        
        if(dp[0][curr]){
            for(int i=0; i<=curr; ++i){
                tmp_s += s[i];
            }
            ret.push_back(vector<string>(1, tmp_s));
        }

        vector<vector<string>> back_res;
        for(int i=1; i<=curr; ++i){
            tmp_s = "";
            if(dp[i][curr]){
                for(int j=i; j<=curr; ++j){
                    tmp_s += s[j];
                }                

                back_res = backforward(s, dp, i-1);
                map[i-1] = back_res; 
                
                for(vector<string> &vec: back_res){
                    vec.push_back(tmp_s);
                    ret.push_back(vec);
                }
            }
        }
        return ret;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), true));
        
        for(int j=1; j<s.length(); ++j){
            for(int i=0; i<j; ++i){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }

        vector<vector<string>> res = backforward(s, dp, s.length()-1);
        return res;
    }
private:
    unordered_map<int, vector<vector<string>>> map;
};


