
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN){ return 0; }
        int sign = (x < 0) ? -1 : 1;
        int res = 0;
        x = abs(x);
        while(x){
            if(res>(INT_MAX/10)){
                return 0;
            }else{
                res = res*10 + (x%10);
                x /= 10;                
            }
        }
        return res*sign;
    }
};