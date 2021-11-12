# 1151. Minimum Swaps to Group All 1's Together

Careful: Yes
Date: November 12, 2021
Difficulty: Medium
Index: 1151
Programming Language: C++
Skills: 1. Maintain a sliding window of width, which is the number of 1's in data;
2. Find the max number of 1's, maxWin, in that window;
3. Then the remaining 0's in the window with max number of 1's, width - maxWin, is the minimum swaps to get a window of all 1's.
Tags: Sliding Window
Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/