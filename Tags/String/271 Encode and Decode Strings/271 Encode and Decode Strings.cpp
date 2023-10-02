// Date: October 2, 2023
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // use chunk character /
        string res;
        for(int i = 0; i < strs.size(); ++i) {
            res += to_string(strs[i].length()) + "//" + strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()) {
            // find delimiter
            auto it = s.find("//", i);
            auto length = stoi(s.substr(i, it-i));
            res.push_back(s.substr(it+2, length));
            i = it+2+length;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
