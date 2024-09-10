
    /*
    Time complexity : O(n)
    Space complexity : O(1)
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
    int gcd(int val1, int val2){
        while(val2 != 0){
            int temp = val2;
            val2 = val1 % val2;
            val1 = temp;
        }
        return val1;

    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* val1 = head;
        ListNode* val2 = head->next;
        while(val1 && val2){
            int g = gcd(val1->val, val2->val);
            ListNode* newNode = new ListNode(g);
            newNode->next = val1->next;
            val1->next = newNode;

            val1 = val2;
            val2 = val1->next;
        }
        return head;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10
    */

    
