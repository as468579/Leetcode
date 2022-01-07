#define TRIP_MAX 1000

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(TRIP_MAX+1, 0);
        int num, from, to;
        for(auto &trip: trips){
            num = trip[0];
            from = trip[1];
            to = trip[2];
            changes[from] += num;
            changes[to] -= num;
        }
        
        int curr = 0;
        for(int i=0; i<(TRIP_MAX+1); i++){
            curr += changes[i];
            if(curr > capacity){ return false; }
        }
        return true;
        
    }
};