// Iterative Version
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){ return mid; }
            else if(nums[mid] > target){ right = mid-1; }
            else { left = mid + 1;}
        }
        return -1;
    }
};

/* Recursive Version
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
*/