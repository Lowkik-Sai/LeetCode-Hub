
    /*
    Time complexity : O(n + m * k) 
where m is the number of unique group sizes
where k is the group size
    Space complexity : O(n + k)
    */


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, stack<int>> freq;
        int groupLen = 0;
        for(int i = 0; i < groupSizes.size(); i++){
            freq[groupSizes[i]].push(i);
            groupLen = max(groupLen, groupSizes[i]);
        }
        vector<vector<int>> result;
        for(auto i : freq){
            vector<int> temp;
            int j = i.first;
            while(freq[i.first].size()){
                temp.push_back(freq[i.first].top());
                freq[i.first].pop();
                j--;
                if(j == 0){
                    result.push_back(temp);
                    temp.clear();
                    j = i.first;
                }
            }
        }

        return result;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
    */

    