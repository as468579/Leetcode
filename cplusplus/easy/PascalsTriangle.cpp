// Iterative version
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
        
//         vector<vector<int>> res;
//         res.push_back(vector<int> (1, 1));
//         if(numRows == 1){ return res; }
        
//         res.push_back(vector<int> (2, 1));
//         if(numRows == 2){ return res; }
        
//         for(int i=2; i<numRows; ++i){
//             vector<int> tmp;
//             tmp.push_back(1);
//             for(int j=1; j<=(i-1);j++){
//                 // cout << "i: " << i << ", j: " << j << endl;
//                 tmp.push_back(res[i-1][j-1] + res[i-1][j]);
//             }
//             tmp.push_back(1);
//             res.push_back(tmp);
//         }
//         return res;
//     }
// };


// Recursive version
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 1){
            res[0] = vector<int>(1, 1);
        }
        else if(numRows == 2){
            res[0] = vector<int>(1, 1);
            res[1] = vector<int>(2, 1);
        }else{
            res = generate(numRows-1);
            vector<int> tmp(numRows, 1);
            for(int i=1; i<=(numRows-2); ++i){
                tmp[i] = res[numRows-2][i-1] + res[numRows-2][i];
            }
            res.push_back(tmp);
        }
        return res;
    }
};