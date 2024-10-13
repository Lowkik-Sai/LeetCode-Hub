
    /*
    Time complexity : O(n log n)
    Space complexity : O(n log n)
    */


class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binary;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            string bin = "";
            while(temp > 0){
                bin = temp % 2 == 0 ? '0' + bin : '1' + bin;
                temp /= 2;
            }
            binary.push_back(bin);
        }
        sort(binary.begin(), binary.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        string bin = "";
        for(auto i : binary){
            bin += i;
        }

        int num = 0;
        int c = 0;
        for(int i = bin.size()-1; i >= 0; i--){
            num += bin[i] == '1' ? pow(2, c) : 0;
            c++;
        }
        return num;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/
    */

    
