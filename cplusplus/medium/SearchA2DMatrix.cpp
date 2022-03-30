class Solution {
private:
    bool search1D(vector<int> &nums, int target){
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] < target){ left = mid + 1; }
            else if(nums[mid] > target){ right = mid - 1; }
            else{ return true; }
        }
        return false;          
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0, right=matrix.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(matrix[mid].back() < target){
                left = mid + 1;
            }else if(matrix[mid].back() > target){
                right = mid;
            }else{
                return true;
            }
        }
        
        return search1D(matrix[left], target);        
    }
};