class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp (n+1, true);
        // vector<int> squares(n, -1);
        // squares[0] = 1;
        vector<int> squares;
        squares.push_back(1);
        
        int max_square = 1;
        int min_index = 1;
        for(int i=2; i<=n; ++i){
            double square_root = sqrt(i);
            if(int(square_root) == square_root) { 
                dp[i] = true;
                squares.push_back(i);
                // squares[min_index] = i;
                // min_index += 1;
                continue;
            }
            
            bool res = true;

            for(vector<int>::iterator it=squares.begin(); it!=squares.end(); it++){
                if((*it) == -1){ break; }
                res = (res && dp[i - (*it)]);
                if(!res){ 
                    dp[i] = true;
                    break;
                }
            }
            if(res){
                dp[i] = false;
            }
        }
        return dp[n];
    }
};