
    /*
    Time complexity : O(n^3 + d)
    Space complexity : O(n^2 + d) (where d is the number of words in the dictionary).
    */


class Solution {
public:
    int getMinExtraChar(string& s, map<string, bool>& freq, int i, vector<int>& dp){
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int minChar = 1e9;
        string subStr = "";
        for(int j = i; j < s.size(); j++){
            subStr += s[j];
            int pick = 1e9, noPick = 1e9;
            if(freq[subStr]) pick = getMinExtraChar(s, freq, j+1, dp);
            noPick = (j - i + 1) + getMinExtraChar(s, freq, j+1, dp);
            minChar = min({minChar, pick, noPick});
        }
        return dp[i] = minChar;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        map<string, bool> freq;
        for(auto& i : dictionary) freq[i] = true;
        vector<int> dp(s.size(), -1);
        return getMinExtraChar(s, freq, 0, dp);
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/extra-characters-in-a-string/
    */

    