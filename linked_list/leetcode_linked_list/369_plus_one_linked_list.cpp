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
    ListNode* plusOne(ListNode* head) {
        int integer=0;
        ListNode*temp=head;
        while(temp){
        	//this will cause integer overflow
        	integer=integer*10+temp->val;
        	temp=temp->next;
        }
        integer++;
        cout<<integer<<endl;
        ListNode *pre=nullptr;
        ListNode *res;
        while(integer){
        	res=new ListNode(integer%10);
        	integer/=10;
        	res->next=pre;
        	pre=res;
        }
        return res;
    }
};

class Solution2 {
public:
    ListNode* plusOne(ListNode* head) {
        vector<int>integer;
        ListNode*temp=head;
        while(temp){
        	//this will cause integer overflow
        	integer.insert(integer.begin(),temp->val);
        	temp=temp->next;
        }

        // for(auto x:integer){
        //     cout<<x<<" ";
        // }
        integer[0]+=1;
        ListNode *pre=nullptr;
        ListNode *res;
        int index=0;
        int count=0;
        while(index<integer.size()){
        	res=new ListNode((integer[index]+count)%10);
        	count=integer[index]+count>=10?1:0;
        	res->next=pre;
        	pre=res;
            index++;
        }
        if(count){
        	res=new ListNode(1);
        	res->next=pre;
        }
        return res;
    }
};