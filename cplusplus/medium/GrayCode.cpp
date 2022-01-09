class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 1){ 
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        vector<int> prev;
        vector<int> prev_reversed;
        prev = grayCode(n-1);
        prev_reversed = prev;
        reverse(prev_reversed.begin(), prev_reversed.end());
        
        for(auto &elem: prev){
            res.push_back(elem);
        }
        
        for(auto &elem: prev_reversed){
            res.push_back(elem+(1<<(n-1)));
        }
        return res;
    }
};