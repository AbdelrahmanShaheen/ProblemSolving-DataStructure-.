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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)return l2;
        if(l2 == nullptr)return l1;
        
        ListNode *l3 ,*p ,*q ,*last;
        p = l1;
        q = l2;
        if(l1->val <= l2->val)
        {
            l3 = l1;
            last = l3;
        }
        else
        {
            l3 = l2;
            last = l3;
        }
        
        while(p && q){
            if(last == nullptr)break;
           if(p->val <= q->val)
            { 
            while((last->val <= q->val))
            {
                p = last;
                last = p->next;
                if(last == nullptr)break;
            }
               p->next = q;
               p = last;
               last = q;
            }
        else
        {
            while((last->val <= p->val))
            {
                q = last;
                last = q->next;
               if(last == nullptr)break;
            }
            q->next = p;
            q = last;
            last = p;
        }    
      } 
        return l3;
    }
};
