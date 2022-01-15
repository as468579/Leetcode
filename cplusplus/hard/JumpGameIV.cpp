class Solution {
private:
    queue<int> q;
        
public:
    int minJumps(vector<int>& arr) {
        
        unordered_map<int, vector<int>> adjacent;            
        for(int i=0; i<arr.size(); ++i){
            adjacent[arr[i]].push_back(i);
        }
        
        // BFS Initialize
        vector<int> distances(arr.size(), 0);
        vector<int> status(arr.size(), 0); // 0, 1, 2
        status[0] = 1;
        q.push(0);
        
        while(!q.empty()){
            int curr_idx = q.front();
            q.pop();
            
            if(curr_idx > 0){
                if(status[curr_idx-1] == 0){
                    distances[curr_idx-1] = distances[curr_idx] + 1;
                    status[curr_idx-1]    = 1;
                    q.push(curr_idx-1);
                }
            }
            
            if((curr_idx+1) < arr.size()){
                if(status[curr_idx+1] == 0){
                    distances[curr_idx+1] = distances[curr_idx] + 1;
                    status[curr_idx+1]    = 1;
                    q.push(curr_idx+1);
                }                
            }
            
            if(adjacent.find(arr[curr_idx]) != adjacent.end()){
                for(auto &nei: adjacent[arr[curr_idx]]){
                    if(status[nei] == 0){
                        distances[nei] = distances[curr_idx] + 1;
                        status[nei]    = 1;
                        q.push(nei);
                    }
                }                
            }
            
            adjacent.erase(arr[curr_idx]);
            status[curr_idx] = 2;
        }
        
        return distances[arr.size()-1];
    }
};