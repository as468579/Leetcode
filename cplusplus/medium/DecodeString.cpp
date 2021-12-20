class Solution {
public:
    string decodeString(string s) {
    
        stack<char> st;
        
        for(auto &ch: s){
            if(ch == ']'){
                char t = st.top();
                st.pop();
                string repeated = "";
                while(t != '['){
                    repeated = t + repeated;
                    t = st.top();
                    st.pop();
                }


                t = st.top();
                st.pop();
                string time_str = "";
                while((t>='0') && (t<='9')){

                    time_str = t + time_str;
                    if(!st.empty()){
                        t = st.top();
                        st.pop();
                    }else{
                        break;
                    }

                }

                int times = stoi(time_str);
                if((t<'0') || (t>'9')){
                    st.push(t);
                }

                for(int i=0; i<times; ++i){
                    for(auto &tmp_r: repeated){
                        st.push(tmp_r);
                    }
                }
            }else{
                st.push(ch);
            }
        }
        
        string res = "";
        while(!st.empty()){
            char ch = st.top();
            res = ch + res; 
            st.pop();
        }
        return res;
        
    }
};