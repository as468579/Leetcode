class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=nums[0], count=1;
        for(int i=1; i<nums.size(); ++i){
            if(curr == nums[i]){
                count += 1;
            }else{
                count -= 1;
                if(count == -1){
                    curr = nums[i];
                    count = 1;
                }
            }
        }
        return curr;
    }
};