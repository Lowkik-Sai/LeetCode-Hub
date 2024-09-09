
    /*
    Time complexity : O(m * n)
    Space complexity : O(m * n)
    */


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));  
        ListNode* curr = head;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int i = 0, j = 0, dir = 0;  

        while (curr) {
            matrix[i][j] = curr->val; 
            curr = curr->next;
            
            int nxtI = i + directions[dir].first;
            int nxtJ = j + directions[dir].second;

            if (nxtI < 0 || nxtI >= m || nxtJ < 0 || nxtJ >= n || matrix[nxtI][nxtJ] != -1) {
                dir = (dir + 1) % 4; 
                nxtI = i + directions[dir].first;
                nxtJ = j + directions[dir].second;
            }

            i = nxtI;
            j = nxtJ;
        }

        return matrix;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09
    */

    
