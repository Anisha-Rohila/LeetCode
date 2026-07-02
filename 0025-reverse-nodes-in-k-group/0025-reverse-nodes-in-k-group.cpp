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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == null || k == 1)
            return head;
        Node* left = head;
        Node* res = null;
        Node* prevleft = null;
        while (left)
        {
            Node* right = left;
            for (int i = 1; i < k && right; i++)
                right = right->next;
            if (right == null)
            {
                if (prevleft)
                    prevleft->next = left;
                break;
            }
            Node* nextGroup = right->next;
            Node* newHead = reverse(left, k);
            if (res == null)
                res = newHead;
            if (prevleft)
                prevleft->next = newHead;
            prevleft = left;
            left = nextGroup;
        }
        return res;
    }
};