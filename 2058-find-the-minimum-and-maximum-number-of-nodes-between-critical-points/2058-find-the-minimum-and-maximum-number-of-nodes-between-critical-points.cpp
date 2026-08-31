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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int firstpos = 0;
        int prevpos = 0;
        int mindist = INT_MAX;
        int i = 1;
        while (curr->next != NULL) {
            if ((prev->val < curr->val && curr->next->val < curr->val) ||
                (prev->val > curr->val && curr->next->val > curr->val)) {
                if (firstpos == 0) {
                    firstpos = i;
                    prevpos = i;
                } else {
                    mindist = min(mindist, -prevpos + i);
                    prevpos = i;
                }
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if (mindist == INT_MAX) {
            return {-1, -1};
        }
        int maxdist = prevpos - firstpos;
        return {mindist, maxdist};
    }
};