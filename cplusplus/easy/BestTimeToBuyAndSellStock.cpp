class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 10001;
        int max = -1;
        int profit = 0;
        for(auto &price: prices){
            if(price < min){
                if((max - min) > profit){
                    profit = (max - min);
                }
                min = price;
                max = price;
            }
            if(price > max){
                max = price;
            }
        }

        if((max-min) > profit){ profit = (max - min); }
        return profit;
    }
};