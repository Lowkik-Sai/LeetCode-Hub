
    /*
    Time complexity : O(n*logn)
    Space complexity : O(1)
    */


class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        long long totalSum = 0;
        for (int i = maximumHeight.size() - 1; i >= 0; --i) {
            if (i < maximumHeight.size() - 1 && maximumHeight[i] >= maximumHeight[i + 1]) {
                maximumHeight[i] = maximumHeight[i + 1] - 1;
            }
            if (maximumHeight[i] <= 0) return -1;
            totalSum += maximumHeight[i];
        }
        return totalSum;

        //TLE

        // long long res = 0;
        // map<int, int> s;
        // vector<int> ind;
        // for(int i = 0; i < maximumHeight.size(); i++){
        //     if(s[maximumHeight[i]] > 0) ind.push_back(i);
        //     res += s[maximumHeight[i]] == 0 ? maximumHeight[i] : 0;
        //     s[maximumHeight[i]]++;
        // }
        // int flag = 0;
        // for(int i = 0; i < ind.size() && !flag; i++){
        //     int temp = maximumHeight[ind[i]];
        //     cout<<temp<<" ";
        //     while(s[temp] != 0 && !flag){
        //         if(temp == 1) flag = 1;
        //         temp--;
        //     }
        //     s[temp]++;
        //     res += temp;
        // }
        // return flag == 0 ? res : -1;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : v
    */

    