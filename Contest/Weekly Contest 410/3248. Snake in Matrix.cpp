
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        for(auto& command : commands){
            if(command == "UP"){
                i -= n;;
            }else if(command == "DOWN"){
                i += n;
            }else if(command == "RIGHT"){
                i += 1;
            }else if(command == "LEFT"){
                i -= 1;
            }
        }
        return i;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/weekly-contest-410/problems/snake-in-matrix/
    */

    
