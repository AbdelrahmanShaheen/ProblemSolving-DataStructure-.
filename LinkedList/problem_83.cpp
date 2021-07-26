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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr1 ,*ptr2;
        ptr1 = head;
        
        if(ptr1 == nullptr)return head;
        
        while(ptr1->next)
        {
            if(ptr1->val == ptr1->next->val)
            {
                ptr2 = ptr1->next;
                ptr1->next = ptr2->next;
                delete ptr2;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        return head;
    }
};
