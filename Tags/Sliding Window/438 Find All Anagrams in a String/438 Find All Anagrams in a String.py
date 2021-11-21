// Date: November 21, 2021
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import Counter
        counter = Counter()
        counter_p = Counter(p)
        res = []
        left = 0
        for i, c in enumerate(s):
            counter[c] += 1
            if i + 1 - left > len(p):
                left_str = s[left]
                if counter[left_str] == 1:
                    del counter[left_str]
                else:
                    counter[left_str] -= 1
                left += 1
            if counter == counter_p:
                res.append(left)
        return res
