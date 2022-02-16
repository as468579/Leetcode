class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> map;
        for(int i=0; i<s.length(); ++i){
            if(map.count(s[i])){
                map[s[i]].second = i;
            }else{
                map[s[i]] = pair<int, int> ({i, i});
            }
        }
        
        vector<pair<int, int>> res(map.size());    
        int i=0;
        for(auto &p: map){
            res[i++] = p.second;
        }
        sort(res.begin(), res.end(), less<pair<int, int>>());   
       
        i=1;
        vector<int> ans(1, res[0].second - res[0].first + 1);
        while(i < res.size()){
            if(res[i].first < res[i-1].second){
                res[i-1].second = max(res[i-1].second, res[i].second);
                ans[ans.size()-1] = (res[i-1].second - res[i-1].first + 1);
                res.erase(res.begin()+i);
            }else{
                ans.push_back(res[i].second - res[i].first + 1);
                ++i;
            }
        }
        
        return ans;
    }
};