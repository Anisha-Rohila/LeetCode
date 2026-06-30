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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode *leftPre=dummy;
        ListNode*currNode=head;

        for(int i=0;i<left-1;i++){
            leftPre=leftPre->next;
            currNode=currNode->next;
        }
        ListNode*subListHead=currNode;
        ListNode*prevNode=nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode*nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
        }
        leftPre->next=prevNode;
        subListHead->next=currNode;
          return dummy->next;
    }
};