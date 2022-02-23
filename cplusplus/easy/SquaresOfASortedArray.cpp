class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int &i: nums){
            i = i * i; 
        }
        
        vector<int> res(nums.size());
        int i=0, j=nums.size()-1, curr = nums.size()-1;
        while(i<=j){
            if(nums[i] > nums[j]){
                res[curr] = nums[i];
                ++i;
            }else if(nums[i] <= nums[j]){
                res[curr] = nums[j];
                --j;
            }
            --curr;
        }
        return res;
    }
};