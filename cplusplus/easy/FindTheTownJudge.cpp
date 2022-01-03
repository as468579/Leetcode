class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>  in_degree(n+1, 0);
        vector<int> out_degree(n+1, 0);
        for(vector<vector<int>>::iterator it=trust.begin(); it!=trust.end(); it++){
            out_degree[(*it)[0]] += 1;
            in_degree[(*it)[1]] += 1;
        }
        
        for(int i=1; i<=n; ++i){
            if((in_degree[i] == (n-1)) && (out_degree[i] == 0)){
                return i;
            }
        }
        return -1;
    }
};