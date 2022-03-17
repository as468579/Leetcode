class Solution {
public:
    int scoreOfParentheses(string s) {
        
        if(s == "()"){ return 1; }
        stack<int> st;
        int score=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '('){ st.push(i); }
            else{
                int t = st.top(), sub_score=0;
                st.pop();
                if(st.empty()){
                    if((t+1) == i){
                        sub_score = 1;
                    }else{
                        sub_score += 2 * scoreOfParentheses(s.substr(t+1, i-t-1));
                    }
                    score += sub_score;
                }
            }
        }
        return score;
    }
};