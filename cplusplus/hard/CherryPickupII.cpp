class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int num_rows = grid.size(), num_cols = grid[0].size();
        int dp[num_rows][num_cols][num_cols];
        for(int k=0; k<num_rows; ++k){
            for(int i=0; i<num_cols; ++i){
                for(int j=0; j<num_cols; ++j){
                    dp[k][i][j] = -1;
                }
            }
        }
        for(int i=0; i<num_cols; ++i){
            for(int j=0; j<num_cols; ++j){
                dp[num_rows-1][i][j] = (i == j) ? (grid[num_rows-1][i]) : (grid[num_rows-1][i]+grid[num_rows-1][j]);
            }
        }
        
        int tmp_i, tmp_j, pick_up_in_curr_row;
        for(int k=num_rows-2; k>=0; --k){
            for(int i=0; i<num_cols; ++i){
                for(int j=0; j<num_cols; ++j){
                    pick_up_in_curr_row = (i == j) ? (grid[k][i]) : (grid[k][i]+grid[k][j]);
                    for(int di=-1; di<=1; ++di){
                        tmp_i = i + di;
                        if((tmp_i < 0) || (tmp_i >= num_cols)){
                            continue;
                        }
                        for(int dj=-1; dj<=1; ++dj){
                            tmp_j = j + dj;
                            if((tmp_j < 0) || (tmp_j >= num_cols)){
                                continue;
                            }
                            // cout << "k+1=" << k+1 << ", tmp_i="<< tmp_i << ", tmp_j=" << tmp_j << ", dp=" << dp[k+1][tmp_i][tmp_j] << endl;
                            dp[k][i][j] = max(dp[k][i][j], dp[k+1][tmp_i][tmp_j] + pick_up_in_curr_row);
                            
                        }
                        
                    }
                }
            }
        }
        /*
        for(int k=0; k<num_rows; ++k){
            for(int i=0; i<num_cols; ++i){
                for(int j=0; j<num_cols; ++j){
                    cout << "k=" << k << ", i=" << i << ", j=" << j << ", dp=" << dp[k][i][j] << endl;
                }
            }
        }
        */
        return dp[0][0][num_cols-1];
    }
};