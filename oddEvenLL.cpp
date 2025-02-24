// approcah#1

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return 0;

        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = even;

        while(even && even -> next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }    
        odd->next = evenHead;
        return head;
    }

    void printList(ListNode* head){
        while(head){
            cout<<head->val << "->";
        }
        cout<<"NULL"<<endl;
    }
};

//approach#2
///using dummy ll

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return 0;

        ListNode* oddPseudo = new ListNode(0);
        ListNode* evenPseudo = new ListNode(0);
        ListNode* odd = oddPseudo;
        ListNode* even = evenPseudo;

        ListNode* curr = head;
        int index = 1;

        while(curr){
            if(index % 2 == 1){
                odd->next = curr;
                odd = odd->next;
            }else{
                even->next = curr;
                even = even-> next;
            }
            curr = curr->next;
            index++;
        }
        even->next = NULL;
        odd->next = evenPseudo->next;       //connecting odd with even

        ListNode* result = oddPseudo->next;         //since even is connected to odd at the end, evenPueodo is deleted
        delete oddPseudo;
        delete evenPseudo;

        return result;
    }

    void printList(ListNode* head){
        while(head){
            cout<<head->val << "->";
        }
        cout<<"NULL"<<endl;
    }
};
