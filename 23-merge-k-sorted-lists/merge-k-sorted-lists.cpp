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
    ListNode* mergetwo(ListNode* l1, ListNode* l2){
        if(!l1) return l2; if(!l2) return l1;
        if(l1->val<l2->val){
            l1->next=mergetwo(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergetwo(l1,l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* divandcon(vector<ListNode*>& lists,int start,int end){
       if(start>end) return NULL;
       if(start==end) return lists[start];
       int mid=start-(start-end)/2;
       ListNode* l1=divandcon(lists,start,mid);
       ListNode* l2=divandcon(lists,mid+1,end);
       return mergetwo(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        return divandcon(lists,0,lists.size()-1);
    }
};