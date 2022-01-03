class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size(), 0);
        vector<int> right_product(nums.size(), 0);
        
        // init
        left_product[0] = 1;
        right_product[nums.size()-1] = 1;
        left_product[1] = nums[0];
        right_product[nums.size()-2] = nums[nums.size()-1];
        
        for(int k=0; k<nums.size(); k++){
            if(k == 0){
                left_product[k] = 1;
                right_product[nums.size()-1-k] = 1;                
            }
            else if(k == 1){
                left_product[k] = nums[0];
                right_product[nums.size()-1-k] = nums[nums.size()-1];
            }
            else{
                left_product[k] = left_product[k-1] * nums[k-1];
                right_product[nums.size()-1-k] = right_product[nums.size()-k] * nums[nums.size()-k];
            }
        }
        
        vector<int> ans(nums.size(), 0);
        for(int i=0; i<ans.size(); ++i){
            ans[i] = left_product[i] * right_product[i];
        }
        
        return ans;
    }
};