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
    ListNode* findSol(ListNode* head,int &cnt,int &k){
        ListNode* curr=head,*prev=NULL,*nxt=NULL;
        int t=0;
        
        if(cnt<k)
            return head;
        
        while(curr!=NULL and t<k){
            t++;
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        cnt=cnt-k;
        if(t==k){
            head->next=findSol(nxt,cnt,k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return findSol(head,cnt,k);
    }
};