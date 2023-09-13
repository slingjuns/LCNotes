// Date: September 13, 2023
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        deque<string> st;
        string buf;
        while(getline(ss, buf, '/')) {
            if(buf.length() > 0) {
                if(buf == ".") continue;
                if(buf == "..") {
                    if(!st.empty()) st.pop_back();
                } else {
                    st.push_back(buf);
                }
            }
        }
        
        // construct result
        string res;
        for(auto str : st){ res += "/" + str;}
        return res == "" ? "/" : res;
        
    }
};
