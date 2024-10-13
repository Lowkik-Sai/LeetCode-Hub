
    /*
    Time complexity : O(n+m)
    Space complexity : O(n)
    */


class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int> freq;
        for(auto& i : bannedWords) freq[i]++;
        int count = 0;
        for(auto& i : message) if(freq[i]) count++;
        return count >= 2;
        
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/report-spam-message/
    */

    
