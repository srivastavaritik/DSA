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
    int pairSum(ListNode* head) {
        ListNode* tmp = head;
        stack<int>st;
        while(tmp) {
            st.push(tmp->val);
            tmp=tmp->next;
        }
        int ans = 0;
        while(st.size()/2) {
            ans=max(ans,st.top()+head->val);
            st.pop();
            head=head->next;
        }
        return ans;
    }
};