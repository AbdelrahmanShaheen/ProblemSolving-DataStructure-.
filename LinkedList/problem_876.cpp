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
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr = head;
        int length = 0;
        while(ptr)
        {
            length++;
            ptr = ptr->next;
        }
        length/=2;
        length++;
        ptr = head;
        for(int i =0 ;i<length-1 ;i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
};
