class Solution {
private:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int curr){
        
        if(target <= 0){ return vector<vector<int>>(); }
        unordered_map<int, vector<vector<int>>> map;
        
        vector<vector<int>> res;
        for(int i=curr; i<candidates.size(); ++i){
            
            if(target == candidates[i]){
                res.push_back(vector<int> (1, target));   
            }
            else{
                vector<vector<int>> cSum = combinationSum(candidates, target-candidates[i], i);
                for(int j=0; j<cSum.size(); ++j){
                    cSum[j].push_back(candidates[i]);
                    res.push_back(cSum[j]);
                }                
            }
        }
        return res;    
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(target <= 0){ return vector<vector<int>>(); }
        return combinationSum(candidates, target, 0);
    }
};