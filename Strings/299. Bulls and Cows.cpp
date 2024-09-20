
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        vector<int> freq(10, 0), vis(n,0);
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bulls++;
                vis[i] = 1;
            }else{
                freq[secret[i]-'0']++;
            }
        }
        for(int i = 0; i < n; i++){
            if(freq[guess[i]-'0'] && !vis[i]){
                freq[guess[i]-'0']--;
                cows++;
            }
        }
        ans += to_string(bulls) + 'A';
        ans += to_string(cows) + 'B';
        return ans;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/bulls-and-cows/
    */

    