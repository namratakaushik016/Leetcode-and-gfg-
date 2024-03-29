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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* R = new ListNode();
        ListNode* temp = R;

        vector<int> help;

        for(int i = 0; i < lists.size(); i++)
        {
            for(;lists[i]; lists[i] = lists[i] -> next)
            {
                help.push_back(lists[i] -> val);
            }
        }

        sort(help.begin(), help.end());

        for(const auto& i : help)
        {
            ListNode* q = new ListNode(i);
            temp -> next = q;
            temp = temp -> next;
        }

        return R -> next;
    }
};