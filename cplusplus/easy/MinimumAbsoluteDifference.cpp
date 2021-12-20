class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;
        int min_diff = 2 * 1000000;
        
        for(int i=0; i < (arr.size() - 1); ++i){
            min_diff = min(min_diff, arr[i+1] - arr[i]);
        }
        
        for(int i=0; i < (arr.size() - 1); ++i){
            if((arr[i+1] - arr[i]) == min_diff){
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[i+1]);
                res.push_back(v);
            }
        }
        return res;
    }