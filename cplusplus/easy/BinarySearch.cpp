class Solution {
private:
    int search(vector<int>&nums, int target, int left, int right){
        if(left == right){ return (nums[left] == target) ? left : -1; }
        
        int mid = (left + right) / 2;
        if(nums[mid] == target)    { return mid; }
        else if(nums[mid] < target){ return search(nums, target, mid+1, right); }
        else { return search(nums, target, left, mid); }
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
};