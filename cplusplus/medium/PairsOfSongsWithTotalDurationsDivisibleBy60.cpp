class Solution {
public:
    int combi(int n, int k){
        if(n == 0){ return 0; }
        
        int res = 1;
        for(int i=n; i>(n-k); --i){
            res = res * i;
        }
        for(int i=2; i<=k; ++i){
            res = res / i;
        }
        return res;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        
        for(vector<int>::iterator it=time.begin(); it!=time.end(); it++){
            count[(*it) % 60] = count[(*it) % 60] + 1;
        }
        
        int res = 0;
        for(int i=0; i<=30; ++i){
            if(i == 0 || i == 30){
                res += combi(count[i], 2);
            }
            
            else{
                res += (count[i] * count[60-i]);
            }
            
            // cout << "i=" << i << ", res="<< res << endl;
        }
        
        return res;
    }
};