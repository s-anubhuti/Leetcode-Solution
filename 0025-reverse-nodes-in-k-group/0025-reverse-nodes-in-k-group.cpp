class Solution {
    ListNode* reversell(ListNode*curr,ListNode*par,ListNode*t1){

        while(curr!=t1){
            ListNode* temp = curr->next ;
            curr->next = par;
            par = curr ;
            curr = temp;
        }
        return par ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // step1 : build intials
        
        ListNode*t1 = head ;
        int counter = 0;
        while(t1 && counter<k){
            t1 = t1->next ;
            counter++;
        }
        if(counter<k) return head ;

        counter = 0;
        ListNode*t2 = t1 ;
        while(t2 && counter<k-1){
            t2 = t2->next ;
            counter++;
        }

        ListNode*anshead  = head ;
        // step 2 : reverse the nodes iteratively

        bool firsttime = true;
        while(t1 && t2){
            if(firsttime){
                anshead = reversell(head,t2,t1) ; 
                firsttime = false;
            }
            else reversell(head,t2,t1);
            head = t1 ;
            t1 = t2->next ;

            counter = 0;
            while(t2 && counter<k){
                t2 = t2->next ;
                counter++;
            }
        }

        if(t1==nullptr || t2==nullptr){
            if(firsttime){
                anshead = reversell(head,t1,t1) ; 
                firsttime = false;
            }
            else reversell(head,t1,t1);
        }
        return anshead;

    }
};