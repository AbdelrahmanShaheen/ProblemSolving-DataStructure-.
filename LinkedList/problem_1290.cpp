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
    long long sum = 0;
    int cnt = 0;
    void solve(ListNode *ptr)
    {
        if(ptr)
        {
          solve(ptr->next);
          if(ptr->val)
          sum+= pow(2 ,cnt);
          cnt++;
        }
    }
    int getDecimalValue(ListNode* head) {
        solve(head);
        return sum;
    }
};
