
    /*
    Time complexity : O(m * k)
    Space complexity : O(n)
    */


class Solution {
public:
    void leftRot(string& dir){
        if(dir == "+Y") dir = "-X";
        else if(dir == "-X") dir = "-Y";
        else if(dir == "-Y") dir = "+X";
        else if(dir == "+X") dir = "+Y";
    }

    void rightRot(string& dir){
        if(dir == "+Y") dir = "+X";
        else if(dir == "-X") dir = "+Y";
        else if(dir == "-Y") dir = "-X";
        else if(dir == "+X") dir = "-Y";
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        string dir = "+Y";
        map<pair<int, int>, bool> obs;
        for(int i = 0; i < obstacles.size(); i++){
            obs[{obstacles[i][0], obstacles[i][1]}] = true;
        }
        int maxDis = 0;
        int x = 0, y =0;
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                rightRot(dir);
                continue;
            }else if(commands[i] == -2){
                leftRot(dir);
                continue;
            }
            int newX = x, newY = y;
            if(dir == "+Y"){
                for(int j = y+1; j <= y + commands[i]; j++){
                    if(obs[{x, j}]) break;
                    newY = j;
                }
            }
            else if(dir == "-X") {
                for(int j = x-1; j >= x - commands[i]; j--){
                    if(obs[{j, y}]) break;
                    newX = j;
                }
            }
            else if(dir == "-Y"){
                for(int j = y-1; j >= y - commands[i]; j--){
                    if(obs[{x, j}]) break;
                    newY = j;
                }
            }
            else if(dir == "+X"){
                for(int j = x+1; j <= x + commands[i]; j++){
                    if(obs[{j, y}]) break;
                    newX = j;
                }
            }
            x = newX;
            y = newY;
            maxDis = max(maxDis, (x*x + y*y));
        }
        return maxDis;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04
    */

    