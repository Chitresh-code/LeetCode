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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> bs=0;
        for (int x: nums) {
            bs[x] = 1;
        } 
        
        ListNode* prev=NULL, *curr=head;
        while (curr) {
            if (bs[curr->val]) { 
                if (prev == NULL) {
                    head = head->next;
                    curr->next = NULL;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};