
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelsMax = 0;
        int currVowels = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                currVowels++;
            }
        }
        vowelsMax = max(vowelsMax, currVowels);
        int i = 1, j = k;
        while(j < s.size()){
            if(s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u'){
                currVowels--;
            }
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                currVowels++;
            }
            vowelsMax = max(vowelsMax, currVowels);
            i++;
            j++;

        }
        return vowelsMax;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
    */

    