
    /*
    Time complexity : O(1)
    Space complexity : O(1)
    */
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int count = 0;
        while(num > 0){
            ans += num % 2 ? 0 : pow(2, count);
            num /= 2;
            count += 1;
        }
        return ans;
    }
};
   /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2024-08-22
    */
