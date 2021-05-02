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
    ListNode* swapNodes(ListNode* head, int k) {
    	int l = 0; 
    	ListNode* cur = head;
    	while(cur){
    		cur = cur -> next; 
    		++l;
    	}

    	cur = head;
    	ListNode* n1 = nullptr;
    	ListNode* n2 = nullptr;
    	for(int i = 1; i <= l; ++i, cur = cur->next){
    		if(i == k) n1 = cur;
    		if(i == l - k + 1) n2 = cur;
    	}
    	swap(n1->val, n2->val);
    	return head;
    }
};