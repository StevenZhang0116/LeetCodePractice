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
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//     	ListNode dl(0);
//     	ListNode dr(0);
//     	ListNode* l = &dl;
//     	ListNode* r = &dr;
//     	while(head){
//     		ListNode*& h = (head->val < x)? l : r;
//     		h = h -> next = head;
//     		head = head -> next;
//     	}
//     	r -> next = nullptr;
//     	l -> next = dr.next;
//     	return dl.next;
//     }
// };


class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    ListNode* left = dummy1;
    ListNode* right = dummy2;
    while (head) {
      if (head->val < x) {\
        left->next = head;
        left = head;
      } else {
        right->next = head;
        right = head;
      }
      head = head->next;
    }
    right->next = nullptr;
    left->next = dummy2->next;
    return dummy1->next;
  }
};