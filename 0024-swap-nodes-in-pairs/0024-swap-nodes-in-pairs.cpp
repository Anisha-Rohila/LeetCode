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
#define null NULL
#define Node ListNode
#define data val
    Node* reverse(Node* head, int times)
    {
        Node* curr = head;
        Node* prev = null;

        while (times-- && curr)
        {
            Node* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head->next = curr;
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == null || head->next == null)
            return head;
        Node* left = head;
        Node* res = null;
        Node* prevleft = null;
        while (left && left->next)
        {
            Node* nextPair = left->next->next;
            Node* newHead = reverse(left, 2);
            if (res == null)
                res = newHead;
            if (prevleft)
                prevleft->next = newHead;
            prevleft = left;
            left = nextPair;
        }
        return res;
    }
};