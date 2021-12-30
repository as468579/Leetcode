class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int length = 1;
        int remainder = 1 % k;
        while(remainder){

            if(length == 536753){ break; }
    
            remainder = (remainder*10 + 1) % k;
            length = length + 1;
        }
        
        if(length == 536753){ return -1; }
        return length;
        
    }
};

