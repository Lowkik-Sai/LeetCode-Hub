
    /*
    Time complexity : O(n + k * log n)
    Space complexity : O(n)
    */


class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for(int i = 0; i < s.size(); i++){
            num += to_string(((s[i]) - 'a' + 1));
        }
        int sum = 0;
        for(int i = 0; i < num.size(); i++){
            sum += (num[i] - '0');
        }
        k -= 1;
        while(k != 0){
            int temp = sum;
            sum = 0;
            while(temp > 0){
                sum += temp % 10;
                temp /= 10;
            }
            k -= 1;
        }
        return sum;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
    */

    
