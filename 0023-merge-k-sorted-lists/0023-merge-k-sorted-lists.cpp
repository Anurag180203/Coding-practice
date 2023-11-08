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
        ListNode*ans = new ListNode(-1),*ret=ans;
        priority_queue<pair<int,ListNode*>>pq;
        for(auto i:lists) {
            if(i)
                pq.push({-(i->val),i});
        }
        while(!pq.empty()) {
            ListNode*temp = pq.top().second;
            pq.pop();
            ans->next = new ListNode(temp->val);
            ans=ans->next;
            if(temp->next)
                pq.push({-(temp->next->val),temp->next});
        }
        return ret->next;
    }
};