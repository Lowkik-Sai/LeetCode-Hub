
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for(int i = 0; i < chalk.size(); i++){
            if(k - sum < chalk[i]) return i;
            sum += chalk[i];
        }
        k = k % sum;
        for(int i = 0; i < chalk.size(); i++){
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
    */

    
