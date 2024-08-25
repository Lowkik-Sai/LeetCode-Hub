    /*
    Time complexity: O(n)
    Space complexity: O(n)
    */
class Solution {
public:
    bool checkPalin(string s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }

    string nearestPalindromic(string n) {
      /* TIME LIMIT EXCEEDED */
        // map<string, bool> vis;
        // vis[n] = true;
        // queue<pair<string, int>> q;
        // q.push({n, 0});
        // while(!q.empty()){
        //     auto [currStr, currDist] = q.front();
        //     q.pop();
        //     if(checkPalin(currStr) && currStr != n) return currStr;
        //     if(!vis[(to_string)(stol(currStr)-1)]){
        //         q.push({(to_string)(stol(currStr)-1), currDist + 1});
        //         vis[(to_string)(stol(currStr)-1)] = true;
        //     }
        //     if(!vis[(to_string)(stol(currStr)+1)]){
        //         q.push({(to_string)(stol(currStr)+1), currDist + 1});
        //         vis[(to_string)(stol(currStr)+1)] = true;
        //     }
        // }
        // return "0";
        if(stol(n) == 1){
            return "0";
        }
        set<string> candidates;
        string prefix = n.substr(0, (n.size() + 1) / 2);
        long long prefixNum = stoll(prefix);
        for(long long i : {-1, 0, 1}){
            string newPrefix = to_string(prefixNum + i);
            string newNum = "";
            if(!(n.size() % 2)){
                newNum = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
            }else{
                newNum = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            candidates.insert(newNum);
        }
        candidates.insert(to_string(static_cast<long long>(pow(10, n.size() - 1)) - 1));
        candidates.insert(to_string(static_cast<long long>(pow(10, n.size())) + 1));
        candidates.erase(n);

        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long num = stoll(n);
        for (const string& candidate : candidates) {
            long long candidateNum = stoll(candidate);
            long long difference = abs(candidateNum - num);
            if (difference < minDifference || (difference == minDifference && candidateNum < stoll(closestPalindrome))) {
                minDifference = difference;
                closestPalindrome = candidate;
            }
        }
        return closestPalindrome;
    }
};
   /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-closest-palindrome/description/
    */  
