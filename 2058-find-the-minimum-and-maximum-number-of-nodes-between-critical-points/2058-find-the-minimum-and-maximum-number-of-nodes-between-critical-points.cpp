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
        vector<int> critical;
        int idx = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        while(next!=NULL){
            if((curr->val>prev->val && curr->val>next->val) || (curr->val<prev->val && curr->val<next->val)){
                critical.push_back(idx);
            }
            prev = curr;
            curr = next;
            next = next->next;
            idx++;
        }
        if(critical.size()<2) return {-1, -1};
        int maxDistance = critical.back()-critical.front();
        int minDistance = INT_MAX;
        for(int i=1;i<critical.size();i++){
            minDistance = min(minDistance, critical[i]-critical[i-1]);
        }
        return {minDistance, maxDistance};
    }
};