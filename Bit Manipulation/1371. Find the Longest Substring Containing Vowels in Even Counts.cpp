
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    int findTheLongestSubstring(string s) {
        int maxLen = 0;
        
        // Vowel state based on their count parity (odd/even)
        vector<int> preSum(5, 0);  // To track counts of 'a', 'e', 'i', 'o', 'u'
        
        // Mapping vowels to their respective index
        map<char, int> mapping;
        mapping['a'] = 0;
        mapping['e'] = 1;
        mapping['i'] = 2;
        mapping['o'] = 3;
        mapping['u'] = 4;
        
        // Map to store the first occurrence of a particular state of vowel counts
        map<vector<int>, int> maps;
        maps[preSum] = -1;  // Initial state: all vowels have appeared 0 times (even)

        // Iterate over the string and update the state of vowel counts
        for (int i = 0; i < s.size(); i++) {
            // Update the vowel count if the current character is a vowel
            if (mapping.find(s[i]) != mapping.end()) {
                preSum[mapping[s[i]]] ^= 1;  // Toggle the parity (odd/even) for this vowel
            }
            
            // If the current state of vowel counts has been seen before
            if (maps.find(preSum) != maps.end()) {
                // Update maxLen based on the length of the valid substring
                maxLen = max(maxLen, i - maps[preSum]);
            } else {
                // If not seen before, store the first occurrence of this state
                maps[preSum] = i;
            }
        }

        return maxLen;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
    */

    