// Date: November 3, 2023
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); ++i) freq[s[i]]++;
            
        string res;
        deque<int> st;
        unordered_set<char> inStack;
        for(int i = 0; i < s.length(); ++i) {
            freq[s[i]]--;
            if(inStack.count(s[i])) continue;
            while(!st.empty() && s[st.back()] >= s[i]) {
                char tmp = s[st.back()];
                if(freq[s[st.back()]] == 0) {
                    break;
                }
                st.pop_back();
                inStack.erase(tmp);
            }
            inStack.insert(s[i]);
            st.push_back(i);
            
        }
        while(!st.empty()) {
            char tmp = s[st.back()];
            st.pop_back();
            res = tmp + res;
        }
        return res;
    }
};
