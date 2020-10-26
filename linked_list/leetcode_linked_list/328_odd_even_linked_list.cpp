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
        ListNode dummy(0);
        ListNode* odd=new ListNode();
        dummy.next=odd;
        ListNode* even=new ListNode();
        ListNode* even_first=even;

        int count=0;
        ListNode* temp=head;
        while(temp){
        	if((count&1)==0){
        		odd->next=temp;
        		odd=odd->next;
                // cout<<"odd value is: "<<odd->val<<endl;
        	}else{
        		even->next=temp;
        		even=even->next;
                // cout<<"even value is: "<<even->val<<endl;
        	}
        	temp=temp->next;
        	count++;
        }
        odd->next=even_first->next;
        even->next=nullptr;
        return dummy.next->next;
    }
};