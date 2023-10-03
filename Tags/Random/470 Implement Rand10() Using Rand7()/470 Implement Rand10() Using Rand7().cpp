// Date: October 3, 2023
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // random 
        int rand48;
        do {
            rand48 = (rand7()-1) * 7 + rand7()-1; // 0-48
        } while(rand48 >= 40);
        int res = rand48 % 10;
        return res == 0 ? 10 : res;
    }
};
