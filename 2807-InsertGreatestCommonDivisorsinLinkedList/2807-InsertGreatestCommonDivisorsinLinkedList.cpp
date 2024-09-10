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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *temp=head, *next_node=head;
        while(temp->next!=NULL)
        {
            
            next_node=temp->next;
            int x =__gcd(temp->val, next_node->val);
            ListNode* newnode=new ListNode(x);

            temp->next=newnode;
            newnode->next=next_node;

            temp=next_node;
        }
        return head;

    }
};