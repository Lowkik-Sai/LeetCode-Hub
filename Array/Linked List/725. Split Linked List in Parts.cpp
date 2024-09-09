
    /*
    Time complexity : O(n+k)
    Space complexity : O(k)
    */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            n += 1;
        }
        vector<int> parts(k, n/k);
        int mod = n % k;
        for(int i = 0; i < mod; i++){
            parts[i] += 1;
        }
        vector<ListNode*> answer(k, NULL);
        curr = head;
        for(int i = 0; i < k; i++){
            answer[i] = curr;
            while(parts[i] > 1 && curr){
                curr = curr->next;
                parts[i] -= 1;
            }
            ListNode* temp = curr ? curr->next : NULL;
            if(curr) curr->next = NULL;
            curr = temp;
        }
        return answer;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/split-linked-list-in-parts/
    */

    
