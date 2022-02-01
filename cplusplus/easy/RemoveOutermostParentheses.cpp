class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res = "";
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '('){
                if(!st.empty()){
                    res += "(";
                }
                st.push('(');
            }
            else{
                if(st.size() != 1){
                    res += ")" ;
                }
                st.pop();
            }
        }
        return res;
    }
};