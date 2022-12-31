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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* arr = new ListNode(0);
        ListNode* ans=arr;
        int carry=0;
        while(l1!=NULL or l2!=NULL){
            if(l1!=NULL and l2!=NULL){
                int value=l1->val+l2->val+carry;
                ListNode* temp= new ListNode(value%10);
                carry=value/10;
                l1=l1->next;
                l2=l2->next;
                arr->next=temp;
                arr=temp;
            }else if(l1==NULL and l2!=NULL){
                int value=l2->val+carry;
                ListNode* temp= new ListNode(value%10);
                carry=value/10;
                l2=l2->next;
                arr->next=temp;
                arr=temp;
            }else if(l1!=NULL and l2==NULL){
                int value=l1->val+carry;
                ListNode* temp= new ListNode(value%10);
                carry=value/10;
                l1=l1->next;
                arr->next=temp;
                arr=temp;
            }
        }
        if(carry>0){
            ListNode* temp= new ListNode(carry);
            arr->next=temp;
            arr=temp;
        }
        return ans->next;
        
    }
};
