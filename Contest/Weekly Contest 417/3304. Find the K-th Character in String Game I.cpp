 
    /*
    Time complexity : O(log k * n)
    Space complexity : O(2^log k)
    */


class Solution {
public:
    char getChar(char c){
        c -= 'a';
        int ascii = c;
        ascii = (c + 1) % 26;
        c = ascii;
        c += 'a';
        return c;
    }

    string getString(string& s){
        string res = "";
        for(int i = 0; i < s.size(); i++){
            res += getChar(s[i]);
        }
        return res;
    }

    char kthCharacter(int k) {
        string s = "a";
        while(s.size() <= k){
            s += getString(s);
            cout<<s<<" ";
        }
        return s[k-1];
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
    */

    
