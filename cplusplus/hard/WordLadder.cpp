class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int exists = 0;
        unordered_map<string, vector<int>> adjacent;
        string tmp_str;
        for(int i=0; i<wordList.size(); ++i){
            tmp_str = wordList[i];
            for(int j=0; j<wordList[0].length(); ++j){
                tmp_str[j] = 'A';
                adjacent[tmp_str].push_back(i);
                tmp_str[j] = wordList[i][j];
            }
            
            if(wordList[i] == endWord){
                exists = 1;
            }
        }
        
        if(!exists){ return 0; }
        
        // BFS
        vector<int>predecessor (wordList.size(), -1);
        vector<int>visited     (wordList.size(), 0); // 
        queue<int> q;
        tmp_str = beginWord;
        for(int i=0; i<beginWord.length(); ++i){
            tmp_str[i] = 'A';
            for(int j=0; j<adjacent[tmp_str].size(); ++j){
                q.push(adjacent[tmp_str][j]);
                visited[adjacent[tmp_str][j]] = 1;
            }
            tmp_str[i] = beginWord[i];
        }

        int curr = -2, adj_ind;
        string curr_str;
        while(!q.empty()){
            curr_str = wordList[q.front()];
            if(curr_str == endWord){ 
                curr = q.front();
                break; 
            }
            
            tmp_str  = curr_str;
            for(int i=0; i<beginWord.size(); ++i){
                tmp_str[i] = 'A';
                for(int j=0; j<adjacent[tmp_str].size(); ++j){
                    adj_ind = adjacent[tmp_str][j];
                    if(!visited[adj_ind]){
                        q.push(adj_ind);
                        visited[adj_ind] = 1;
                        predecessor[adj_ind] = q.front();
                    }
                }
                tmp_str[i] = wordList[q.front()][i];
            }
            q.pop();
        }
        
        if(curr == -2){ return 0; }
        
        int count = 1;
        while(curr != -1){
            curr = predecessor[curr];
            count += 1;
        }
        return count;
    }
};
