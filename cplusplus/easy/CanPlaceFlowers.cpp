/* Version I
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
*/

// Version II
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int acc = 0;
        int prev = -1;
        int complement;
        for(int i=0; i<flowerbed.size(); ++i){
            if(flowerbed[i]){
                complement = (prev == -1) ? 1 : 2;
                acc += ((i - prev - complement) / 2);
                prev = i;
            }
        }
        
        if(prev == -1){
            return (((flowerbed.size() + 1)/2) >= n);
        }
        
        if(prev != (flowerbed.size()-1)){
            acc += ((flowerbed.size() - prev -1) / 2);
        }
        return (acc >= n);
    }
};
    