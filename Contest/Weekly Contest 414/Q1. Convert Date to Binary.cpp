
    /*
    Time complexity : O(n * log n)
    Space complexity : O(n)
    */

class Solution {
public:
    string convertToBin(string s, int count){
        int num = stoi(s);
        string res = "";
        int c = 0;
        while(num > 0){
            if(num % 2 != 0) res = '1' + res;
            else res = '0' + res;
            num /= 2;
            c += 1;
        }
        return res;
    }
    string convertDateToBinary(string date) {
        int count = 0;
        string s = "";
        string res = "";
        for(int i = 0; i <= date.size(); i++){
            if(i == date.size() || date[i] == '-'){
                res += convertToBin(s, count);
                if(date[i] == '-') res += '-';
                s = "";
            }else s += date[i];
        }
        return res;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/weekly-contest-414/problems/convert-date-to-binary/
    */
