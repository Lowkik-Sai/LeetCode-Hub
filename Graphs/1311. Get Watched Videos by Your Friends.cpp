
    /*
    Time complexity: O(V * L * log(V * L))       V: number of users
    Space complexity: O(V * L)                   L: maximum length of a watchedVideos list
                                   
    */
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<int> levelList(n, -1);
        queue<int> q;
        q.push(id);
        levelList[id] = 0;

        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            int currLevel = levelList[currNode];
            
            if (currLevel == level) continue;

            for (int frd : friends[currNode]) {
                if (levelList[frd] == -1) {
                    levelList[frd] = currLevel + 1;
                    q.push(frd);
                }
            }
        }

        map<string, int> videoFreq;
        for (int i = 0; i < n; i++) {
            if (levelList[i] == level) {
                for (const string& vid : watchedVideos[i]) {
                    videoFreq[vid]++;
                }
            }
        }

        vector<pair<string, int>> freqVector(videoFreq.begin(), videoFreq.end());
        sort(freqVector.begin(), freqVector.end(), [](pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });

        vector<string> result;
        for (auto& p : freqVector) {
            result.push_back(p.first);
        }
        
        return result;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/get-watched-videos-by-your-friends/
    */

