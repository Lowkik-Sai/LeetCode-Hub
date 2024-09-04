
    /*
    Time complexity : O(1)
    Space complexity : O(1)
    */

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;
        for(int i = 0; i <= 3; i++){
            int n1 = num1 > 0 ? num1 % 10 : 0;
            int n2 = num2 > 0 ? num2 % 10 : 0;
            int n3 = num3 > 0 ? num3 % 10 : 0;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            key += min({n1, n2, n3})*pow(10,i);
        }
        return key;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/biweekly-contest-138/problems/find-the-key-of-the-numbers/
    */

    
