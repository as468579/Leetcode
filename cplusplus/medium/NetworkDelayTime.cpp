typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adjacents(n+1);
        for(int i=0; i<times.size(); ++i){
            adjacents[times[i][0]].push_back(make_pair(times[i][2], times[i][1]));
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dists(n+1, INT_MAX);
        dists[k] = 0; 
        pq.push({0, k});
        while(!pq.empty()){
            pii curr = pq.top();
            pq.pop();
            for(pii &adj: adjacents[curr.second]){
                if(dists[adj.second] > (dists[curr.second] + adj.first)){
                    dists[adj.second] = dists[curr.second] + adj.first;
                    pq.push({dists[adj.second], adj.second});
                }
            }
        }
        
        int m=0;
        for(int i=1; i<dists.size(); ++i){
            if(dists[i] == INT_MAX){ return -1; }
            m = max(m, dists[i]);
        }
        return m; 
    }
};