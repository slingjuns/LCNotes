from bisect import bisect_left
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        # Preprocessing the colors
        color_index = {}
        for i, c in enumerate(colors):
            if c in color_index: color_index[c].append(i)
            else: color_index[c] = [i]
        res = []
        for i, c in queries:
            if c not in color_index: 
                res.append(-1)
                continue
            index_list = color_index[c]
            dist_prev_i, dist_after_i = float("inf"), float("inf")
            loc = bisect_left(index_list, i)
            prev_loc = loc - 1
            dist_prev_i = index_list[prev_loc]-i if prev_loc >= 0 else float("inf")
            dist_after_i = i-index_list[loc] if loc < len(index_list) else float("inf")
            minv = min(dist_prev_i, dist_after_i)
            res.append(minv)
        return res
