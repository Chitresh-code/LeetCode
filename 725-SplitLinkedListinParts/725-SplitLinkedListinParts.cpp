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
        vector<ListNode*>res;
        if(head==NULL)
        {
            res.resize(k,NULL);
            return(res);
        }
        //vector<int>array;
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            count++;
        }
        int remval = 0;
        if(count%k==0)
        remval = 0;
        int val = (count/k);
        remval+= count%k;
        //array.resize(k,count/k);
        temp = head;
        int i = 0;
        for(i=0;i<k;i++)
        {
            if(temp==NULL)
                break;
            int size = val-1;
            if(remval>0)
            {
             size++;
             remval--;
            }
            res.push_back(temp);
            while(size-- && temp->next!=NULL)
                temp = temp->next;
            ListNode *k = temp->next;
            temp->next = NULL;
            temp = k; 
        }
        while(i<k)
        {
            res.push_back(NULL);
            i++;
        }
        return(res);
    }
};