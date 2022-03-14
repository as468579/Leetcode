class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int index=0;
        while(index < ((int)path.length() - 1)){
            if((path[index] == '/') && (path[index+1] == '/')){
                path.erase(path.begin() + index);
            }else{
                index += 1;
            }
        }
        
        const char *d = "/";
        char *c_path  = (char*)malloc(path.length()+1);
        strcpy(c_path, path.c_str());
        char *p = strtok(c_path, d);
        string filename = "";
        while (p != NULL) {
            filename = string(p);
            if(filename == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }else if(filename != "."){
                st.push(filename);
            }
            p = strtok(NULL, d);		   
        }
        if(st.empty()){ return string("/"); }
        
        string res="";
        while(!st.empty()){
            res =  "/" + st.top() + res;
            st.pop();
        }
        return res;   
    }
};