class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int devices_in_prev_row = 0, devices_in_curr_row = 0, num_beams = 0;
        for(auto &str: bank){
            devices_in_curr_row = 0;
            for(char c: str){
                if(c == '1'){ devices_in_curr_row += 1; }
            }
            num_beams += devices_in_prev_row * devices_in_curr_row;
            if(devices_in_curr_row){ 
                devices_in_prev_row = devices_in_curr_row;
            }
        }
        return num_beams;
    }
};