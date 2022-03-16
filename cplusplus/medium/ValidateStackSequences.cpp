class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i_pop=0, i_push=0;
        
        while((i_push < pushed.size()) 
//               (i_pop  < popped.size())
             ){
            
            st.push(pushed[i_push++]);
            
            while((!st.empty()) &&
//                   (i_pop < popped.size()) &&
                  (st.top() == popped[i_pop])
                 ){        
                st.pop();
                i_pop += 1;
            }
        }
        return (st.empty()) && (i_pop == popped.size());
    }
};
