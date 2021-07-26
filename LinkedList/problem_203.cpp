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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == nullptr)
            return head;
        ListNode *ptr = head;
        ListNode *ptr2 = head;
        while(head->val == val)
        {
            head = head->next;
            delete ptr;
            ptr = head;
            ptr2 = head;
            if(head == nullptr)return head;
        }
        while(ptr)
        {
            if(ptr->val != val)
            {
                ptr2 = ptr;
                ptr = ptr->next;
            }
            else{
                ptr2->next = ptr->next;
                delete ptr;
                ptr = ptr2->next;
            }
        }
        return head;
    }
};
