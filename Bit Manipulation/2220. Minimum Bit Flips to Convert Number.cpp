
    /*
    Time complexity : O(log(max(start, goal)))
    Space complexity : O(1)
    */


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int numChanges = 0;
        if(start < goal) swap(start, goal);
        while(start > 0){
            int startBit = start & 1;
            int goalBit = goal & 1;
            if(startBit != goalBit)numChanges += 1;
            start >>= 1;
            goal >>= 1;
        }
        return numChanges;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
    */

    