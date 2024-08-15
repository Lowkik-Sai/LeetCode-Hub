  /*
    Time complexity : O(n) - n is size of arr
    Space complexity : O(1)
    */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) five += 1;
            else if(bills[i] == 10){
                if(five > 0){
                    five -= 1;
                    ten += 1;
                }else return false;
            }else if(bills[i] == 20){
                if(ten > 0 && five > 0){
                    ten -= 1;
                    five -= 1;
                }else if(five >= 3){
                    five -= 3;
                }else return false;
            }
        }
        return true;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-15
    */
