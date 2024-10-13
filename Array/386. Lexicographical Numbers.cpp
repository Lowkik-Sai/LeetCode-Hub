
    /*
    Time complexity : O(n * log n)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for(int i = 1; i <= n; i++){
            res.push_back(curr);
            // int power = 1;
            // int num = 0;
            // int currNum = i*pow(10,power);
            // while(currNum <= n){
            //     res.push_back(currNum);
            //     num++;
            //     currNum++;
            //     if(num == 10){
            //         num = 0;
            //         power++;
            //         currNum = i*pow(10,power);
            //     }
            // }
            if(curr*10 <= n){
                curr *= 10;
            }else{
                while(curr % 10 == 9 || curr >= n){
                    curr /= 10;
                }
                curr++;
            }
        }
        return res;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/lexicographical-numbers/
    */

    