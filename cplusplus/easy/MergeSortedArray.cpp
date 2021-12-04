class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3 = nums1;
        
        int i=0; int j=0;
        while((i<m) and (j<n)){
            if(nums3[i] < nums2[j]){
                nums1[i+j] = nums3[i];
                i = i+1;
            }
            else{
                nums1[i+j] = nums2[j];
                j = j+1;
            }
        }
        if(i==m){
            for(;j<n;j++){ nums1[i+j] = nums2[j]; }
        }
        if(j==n){
            for(;i<m;i++){ nums1[i+j] = nums3[i]; }
        }
    }
};