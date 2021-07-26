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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr)return head;
        ListNode *ptr ,*ptr2 ,*last;
        ptr2 = head;
        ptr = head;
        while(ptr)
        {
            ptr2 = ptr2->next;
            if(ptr == head)
            {       
                ptr->next = nullptr;
                last = ptr;
                ptr = ptr2;   
            }
            else
            {
                ptr->next = last;
                last = ptr;
                ptr = ptr2;
            }
        }
        head = last;
        return head;
    }
};
