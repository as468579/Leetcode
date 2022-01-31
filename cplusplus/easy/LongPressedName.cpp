class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        if(name[0] != typed[0]){ return false; }
        
        char prev = name[0];
        int i = 1, j = 1;
        while((i < name.size()) && (j < typed.size())){
            // cout << "i: " << i << ", j: " << j << endl;
            if(j == typed.size()) { return false; }
            
            if(name[i] == typed[j]){
                prev = name[i];
                i += 1;
                j += 1;
            }            
            else if(typed[j] == prev){
                j += 1;
            }
            else if(typed[j] != prev){
                return false;
            }
        }
        
        if(i < name.size()){ return false; }
        
        while(j < typed.size()){
            if(typed[j] == prev){ j = j + 1; }
            else{ return false; }
        }
        
        return true;
    }
};