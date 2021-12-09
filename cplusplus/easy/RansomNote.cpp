class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(auto &s: magazine){
            if(m.count(s)){ m[s] += 1; }
            else{ m[s] = 1; }
        }
        
        for(auto &s:ransomNote){
            if((m.find(s) != m.end()) && m[s]) { m[s] -= 1; }
            else{ return false; }
        }
        return true;
    }
};