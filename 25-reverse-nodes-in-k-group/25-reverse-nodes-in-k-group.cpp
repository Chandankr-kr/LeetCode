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
    ListNode* findSol(ListNode* head,int k,int &cnt){
        if(cnt<k)
            return head;
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
        int count=0;
        while(count<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        
        cnt-=k;
        if(count==k){
            head->next=findSol(curr,k,cnt);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        
        return findSol(head,k,cnt);
    }
};