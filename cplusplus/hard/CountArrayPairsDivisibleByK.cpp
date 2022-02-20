vector<int> precalc[100001];
int num[100001];

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        for (int i=0; i<=100000; i++) num[i] = 0;
        if (precalc[2].empty()) {
            for (int i=1; i<=100000; i++) {
                for (int j=i; j<=100000; j+=i) precalc[j].push_back(i);
            }
        }
        long long ans = 0;
        for (int i : nums) {
            int z = k / gcd(k, i);
            ans += num[z];
            z = gcd(k, i);
            for (int i : precalc[z]){
                num[i]++;
            };
        }
        return ans;
    }
};