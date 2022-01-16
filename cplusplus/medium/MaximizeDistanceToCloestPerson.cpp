class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        vector<int> continuous;
        
        // Count and record the amout of continuous zeros
        int count = 0;
        for(int i=0; i<seats.size(); ++i){
            if(seats[i]){
                if(i){
                    continuous.push_back(count);   
                }
                count = 0;
            }
            else{
                count += 1;
            }
        }
        if(count){
            continuous.push_back(count);
        }
        
        
        // Rules:
        // The distance to the closest nearby person is ceil(continuous[1]/2)
        // Special Cases:
        // if seats[0] == 0, the distance at the leftest side is continuous[0] 
        // if seats[1] == 0, the distance at the rightest side is continuous[continuous.size() - 1] 
        int start = seats[0] ? 0 : 1;
        int end   = (seats[seats.size()-1]) ? (continuous.size()) : (continuous.size()-1);
        
        // Rules
        int max_dist = 0;
        for(int i=start; i<end; ++i){
            continuous[i] = ceil((continuous[i]/2.0));
            max_dist = max(max_dist, continuous[i]);
        }
        
        // Special Cases
        if(seats[0] == 0){
            max_dist = max(max_dist, continuous[0]);
        }
        if(seats[seats.size()-1] == 0){
            max_dist = max(max_dist, continuous[continuous.size()-1]);
        }
        return max_dist;
    }
};