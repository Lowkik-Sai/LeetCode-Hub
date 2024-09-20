
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k == s.size()) return true;
        else if(k > s.size()) return false;

        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }
        int singles = 0;
        for(int i = 0; i < 26; i++) if(freq[i] % 2 == 1) singles++;
        if(singles > k) return false;
        return true;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/construct-k-palindrome-strings/
    */

    