class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool checkR[9][9];
        bool checkC[9][9];
        bool checkB[9][9];
        
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                checkR[i][j] = false;
                checkC[i][j] = false;
                checkB[i][j] = false;
            }
        }
        
        int num;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] != '.'){
                    num = board[i][j] - '1';
                    if(checkR[i][num]){ return false; }
                    if(checkC[j][num]){ return false; }
                    if(checkB[(i/3)*3+(j/3)][num]) { return false; }
                    checkR[i][num] = true;
                    checkC[j][num] = true;
                    checkB[(i/3)*3+(j/3)][num] = true;   
                }
            }
        }
        return true;
    }
};