class Solution {
private:
    bool isUpperCase(char c){
        return (c >= 'A' and c <= 'Z');
    }
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1){ return true; }
        if( (!isUpperCase(word[0])) && (isUpperCase(word[1]))){
            return false;
        }
        
        int mode = isUpperCase(word[1]);
        for(int i=2; i<word.length(); ++i){
            if( mode && (!isUpperCase(word[i])) ){ return false; }
            else if( (!mode) && isUpperCase(word[i]) ){ return false; }
        }
        return true;
    }
};