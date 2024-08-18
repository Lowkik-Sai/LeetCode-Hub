
    /*
    Time complexity : O(2^n)
    Space complexity : O(n)
    */
class Solution {
public:
    void countSubStrings(string& s, int& k, int& count, int& ones, int& zeros, int i){
        if(i >= s.size()) return ;
        if(s[i] == '1') ones += 1;
        else zeros += 1;
        
        if((ones <= k || zeros <= k) && (ones > 0 || zeros > 0))  count += 1;
        
        
        countSubStrings(s, k, count, ones, zeros, i+1);
        if(s[i] == '1') ones -= 1;
        else zeros -= 1;
    }
    
    int countKConstraintSubstrings(string s, int k) {
        int ones = 0;
        int zeros = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            countSubStrings(s, k, count, ones, zeros, i);
        }
        return count;
    }
};
   /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/
    */
