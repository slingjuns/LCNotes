// Date: November 3, 2023
class Solution {
public:
    bool winnerOfGame(string colors) {
        // count how many rounds can I pick A == how many AAA
        int left = 0, count_A = 0, count_B = 0;
        for (int i = 0; i < colors.size();) {
            while(i < colors.size() && colors[i] == colors[left]) ++i;
            int count = max(0, i-left-2);
            if(colors[left] == 'A') count_A += count;
            else count_B += count;
            left = i;
        }
        return count_A > count_B;
    }
};
