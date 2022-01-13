bool compare(vector<int> &a, vector<int> &b){
    return (a[1] < b[1]);
}

class Solution {

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        
        int curr_index = 0;
        int comp_index = curr_index+1;
        int res = 1;
        while(comp_index < points.size()){
            if(points[comp_index][0] > points[curr_index][1]){
                res += 1;
                curr_index = comp_index;
                comp_index = curr_index+1;
            }else{
                comp_index += 1;
            }
        }
        return res;
    }
};



// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//                      1  1  1  1  1  1  1
//     1 1 1 1 1 1 1
//   1 1 1 1 1 
//               1 1 1  1  1  1