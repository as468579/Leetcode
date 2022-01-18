class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int acc = 0;
        int count = 0;
        for(int i=0; i<flowerbed.size(); ++i){
            if(flowerbed[i]){
                acc += (count / 2);
                count = -1;
            }else{
                count += 1;
            }
        }

        return ((acc + ((count + 1) / 2)) >= n);
    }
};
    