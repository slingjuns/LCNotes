class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        ans = ""
        ls = list(s)
        stack = []
        for i,c in enumerate(ls):
            if c == ")":
                if not stack:
                    ls[i] = ""
                else:
                    stack.pop()
            elif c == "(":
                stack.append(i)
        for i in stack:
            ls[i] = ""
        return "".join(ls)
