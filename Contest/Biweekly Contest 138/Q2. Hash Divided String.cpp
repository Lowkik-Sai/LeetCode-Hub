
    /*
    Time complexity : O(n)
    Space complexity : O(n/k)
    */


class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int n = s.size();
        for(int i = 0; i < n; i += 0){
            int temp = k;
            int hash = 0;
            while(i < n && temp >= 1){
                hash += int(s[i] - 'a');
                i += 1;
                temp -= 1;
            }
            result += char(hash % 26) + 'a';
        }
        return result;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : Q2. Hash Divided String
    */

    
