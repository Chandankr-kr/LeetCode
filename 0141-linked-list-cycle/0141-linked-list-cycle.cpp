/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s1;
        while(head){
            if(s1.find(head)!=s1.end())
                return true;
            s1.insert(head);
            head=head->next;
        }
        return false;
    }
};