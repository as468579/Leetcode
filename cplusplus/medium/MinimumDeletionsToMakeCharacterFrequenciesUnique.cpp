vector<pair<int, int>> charFreqs(26);

class Solution {
public:
    int minDeletions(string s) {
        
        // initialize charFreqs
        for(int i=0; i<26; ++i){
            charFreqs[i] = pair<int, int>({0, i});    
        }
        
        for(int i=0; i<s.length(); ++i){
            charFreqs[s[i] - 'a'].first++;
        }
        
        
        sort(charFreqs.begin(), charFreqs.end(), greater<pair<int, int>>());
        
        // for(int i=0; i<charFreqs.size(); ++i){
        //     if(charFreqs[i].first){
        //         cout << charFreqs[i].first << " " << charFreqs[i].second << endl;
        //     }
        // }
        
        int prev = charFreqs[0].first;
        int res = 0;
        for(int i=1; i<charFreqs.size(); ++i){
            // 1 1
            // 2 0
            // cout << charFreqs[i].first << " " << prev << endl;
            if(charFreqs[i].first >= prev){
                
                if(prev){
                    res += (charFreqs[i].first - prev + 1);
                    charFreqs[i].first = prev - 1;  
                }else{
                    res += charFreqs[i].first;
                    charFreqs[i].first = 0; 
                }
            }
            prev = charFreqs[i].first;
        }
        return res;
        
    }
};