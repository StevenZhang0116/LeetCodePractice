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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* fast = head;
    	for(int i = 0; i < n; ++i){
    		fast = fast -> next;
    	}
    	ListNode dummy(0);
    	dummy.next = head;
    	ListNode* prev = &dummy;
    	while(fast){
    		fast = fast -> next;
    		prev = prev -> next;
    	}
    	ListNode* node = prev -> next;
    	prev -> next = node -> next;
    	delete node;
    	return dummy.next;
    }
};