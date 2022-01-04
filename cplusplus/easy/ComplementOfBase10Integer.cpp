class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) { return 1; }
        int shfits = floor(log2(n));
        unsigned int max = 1;
        max = (max << (shfits +1));
        max = max - 1;
        return max^n;
    }
};