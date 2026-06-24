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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<int> values;
        while(temp != NULL){
            values.push_back(temp-> val);
            temp = temp -> next;
        }
        
        int i = 0;
        int j = values.size() - 1;
        temp = head;
        bool front = true;
        while(temp!=NULL){
            if(front){
                temp-> val = values[i++];
            }
            else{
                temp-> val = values[j--];
            }

            front = !front;
            temp = temp-> next;
        }
    }
};