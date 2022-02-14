class Solution {
public:
    int rotatedDigits(int n) {
        
        // 0 1 2 3 4 5 6 7 8 9
        // 1 1 2 0 0 2 2 0 1 2
        vector<int> symbols({1, 1, 2, 0, 0, 2, 2, 0, 1, 2});
            
        int reverse, invalid, tmp;
        int res = 0;
        for(int i=2; i<=n; ++i){
            reverse = 0;
            tmp = i;
            while(tmp){
                if(symbols[tmp % 10] == 2){ 
                    reverse++; 
                }else if(symbols[tmp % 10] == 0){
                    break;
                }
                tmp /= 10;
            }
            
            if((!tmp) && reverse){
                res += 1;
            }
        }
        return res;
    }
};