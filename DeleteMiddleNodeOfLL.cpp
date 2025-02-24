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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head; 
        ListNode* prev = NULL;    

        while(fast && fast->next){
            prev = slow;  //prev is previous slow node
            slow = slow->next; //slow is next to prev node
            fast = fast -> next -> next; //fast is two step ahead to slow
        } 

        prev->next = slow->next;    //pointing previous node to next node
        delete slow;                //deleting slow (which will asct as middle node)
        return head;                //return LL after deletion
    }
};
