
    /*
    Time complexity: O(n^2 * log n^2)
    Space complexity: O(1)
    */
class Solution {
public:
    bool check(int& n1, int& n2){
        
        string num2 = to_string(n2);
        if(n1 == n2) return true;
        for(int i = 0; i < num2.size(); i++){
            for(int j = i+1; j < num2.size(); j++){
                string temp = num2;
                swap(temp[i], temp[j]);
                if((stoi)(temp) == n1) return true;
            }
        }
        
        string num1 = to_string(n1);
        if(n1 == n2 && num1.size() == 1) return true;
        for(int i = 0; i < num1.size(); i++){
            for(int j = i+1; j < num1.size(); j++){
                string temp = num1;
                swap(temp[i], temp[j]);
                if((stoi)(temp) == n2) return true;
            }
        }
        
        return false;
    }
    
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(check(nums[i], nums[j])) count += 1;
            }
        }
        return count;
    }
};
    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/weekly-contest-412/problems/count-almost-equal-pairs-i/
    */
