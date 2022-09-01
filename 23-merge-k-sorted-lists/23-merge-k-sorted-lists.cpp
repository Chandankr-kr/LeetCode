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
class comparator{
    public:
    bool operator()(ListNode* l1,ListNode* l2){
        return l1->val>l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator> pq1;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i])
            pq1.push(lists[i]);
        }
        
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        
        while(pq1.size()){
            auto curr=pq1.top();
            pq1.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr and curr->next){
                curr=curr->next;
                pq1.push(curr);
            }
        }
        return head->next;
    }
};