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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* n=nullptr;
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* curr=nullptr;
        if(l1==nullptr&&l2!=nullptr){
            return l2;
        }
        if(l2==nullptr&&l1!=nullptr){
            return l1;
        }
        if(l1==nullptr&&l2==nullptr){
            return nullptr;
        }
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<=l2->val){
                int v=l1->val;
                ListNode* a=new ListNode(v);
                if(n==nullptr){
                    n=a;
                    curr=n;
                    l1=l1->next;
                }
                else{
                    curr->next=a;
                    curr=curr->next;
                    l1=l1->next;
                }
            }
            else{
                int v=l2->val;
                ListNode* a=new ListNode(v);
                if(n==nullptr){
                    n=a;
                    curr=n;
                    l2=l2->next;
                }
                else{
                    curr->next=a;
                    curr=curr->next;
                    l2=l2->next;
                }
            }
        }
        while(l1!=nullptr){
            int v=l1->val;
            ListNode* a= new ListNode(v);
            curr->next=a;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2!=nullptr){
            int v=l2->val;
            ListNode* a=new ListNode(v);
            curr->next=a;
            curr=curr->next;
            l2=l2->next;
        }
        return n;
    }
};
