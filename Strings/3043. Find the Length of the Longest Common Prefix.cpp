
    /*
    Time complexity : O(n1 * log n1 + n2 * log n2)
    Space complexity : O(n1 * log n1)
    */


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> freq;
        for(int i = 0; i < arr1.size(); i++){
            string temp = to_string(arr1[i]);
            string curr = "";
            for(int j = 0; j < temp.size(); j++){
                curr += temp[j];
                if(freq.find(curr) == freq.end()) freq.insert(curr);
            }
        }
        int maxLen = 0;
        for(int i = 0; i < arr2.size(); i++){
            string temp = to_string(arr2[i]);
            string curr = "";
            for(int j = 0; j < temp.size(); j++){
                curr += temp[j];
                if(freq.find(curr) != freq.end()) maxLen = max(maxLen, (int)curr.size());
            }
        }
        return maxLen;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
    */

    