# 524. Longest Word in Dictionary through Deleting

Careful: No
Date: October 3, 2022
Difficulty: Medium
Index: 524
Programming Language: C++
Tags: Two Pointers, Two Sequence
Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b){
            if (a.length() == b.length()) {
                return a<b;
            }
            return a.length() > b.length();
        });
        
        for (string word: dictionary) {
            if (word.length() > s.length()) continue;
            int left = 0, right = 0; // word length is always shorter than tmp
            while (left < word.length() && right < s.length()) { // check is subsequence
                if (word[left] == s[right]) {
                    left++;
                    right++;
                } else {
                    right++;
                }
            }
            if (left >= word.length()) return word;
        }
        return "";
    }
};
```