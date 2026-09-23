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
    ListNode* mergeTwoLists(ListNode* l1 ,ListNode* l2 ) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1=l1->next;
            }
            else
            {
                curr->next = l2;
                l2= l2->next;
            }
            curr = curr->next;
        }
        if(l1!=NULL) curr->next = l1;
        else curr->next = l2;

        return dummy.next;
    }
    ListNode* helper(vector<ListNode*>& lists, int start, int end)
    {
        if(start == end) return lists[start];
        if(start + 1 == end) 
            return mergeTwoLists(lists[start], lists[end]);
        int mid = start + (end-start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid+1, end);
        return mergeTwoLists(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return helper(lists, 0, lists.size()-1);
    }
};
