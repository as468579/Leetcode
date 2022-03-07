class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int curr = nums[0];
        vector<int> res1;
        for(int i=1; i<nums.size(); ++i){
            if(gcd(curr, nums[i]) == 1){
                res1.push_back(curr);
                curr = nums[i];
            }else{
                curr = lcm(curr, nums[i]);;
            }
        }
        res1.push_back(curr);
        
        int merge = 0;
        curr = res1[res1.size()-1];
        vector<int> res2;
        for(int i=res1.size()-2; i>=0; --i){
            if(gcd(curr, res1[i]) == 1){
                res2.push_back(curr);
                curr = res1[i];
            }else{
                merge = 1;
                curr = lcm(curr, res1[i]);;
            }           
        }
        res2.push_back(curr);
        reverse(res2.begin(), res2.end());
        if(merge){ 
            return replaceNonCoprimes(res2);
        }else{
            return res2;   
        }      

    }
};