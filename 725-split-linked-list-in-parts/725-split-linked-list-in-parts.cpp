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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,NULL);
        int cnt=0;
        ListNode* prev=NULL,*temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        
        int n=cnt/k,t=cnt%k;
        for(int i=0;head and i<k;i++,t--){
            res[i]=head;
            for(int j=0;j<n + (t>0);j++){
                prev=head;
                head=head->next;
            }
            prev->next=NULL;
        }
        return res;
    }
};