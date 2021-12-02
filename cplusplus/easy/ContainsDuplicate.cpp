class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> s;
        for(auto &n: nums){
            if(s.count(n)){ return true; }
            s.insert(n);
        }
        return false;
    }
};