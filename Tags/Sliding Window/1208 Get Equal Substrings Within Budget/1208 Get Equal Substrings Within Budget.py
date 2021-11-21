// Date: November 21, 2021
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        left = maxv = curCost = 0
        for i, (c1, c2) in enumerate(zip(s, t)):
            curCost += abs(ord(c2) - ord(c1))
            if curCost > maxCost:
                while curCost > maxCost:
                    tmpc1, tmpc2 = s[left], t[left]
                    curCost -= abs(ord(tmpc1) - ord(tmpc2))
                    left += 1
            maxv = max(i - left + 1, maxv)
        return maxv
