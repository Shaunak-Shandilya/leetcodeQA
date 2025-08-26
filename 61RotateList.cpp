

//MY SOLN V1 TIME EXPENSIVE

class Solution {
public:
    ListNode* ABCD(ListNode* head) {
        //small linked list edge cases
        if (!head) return head;
        if (!head->next) return head;
        
        ListNode * mover = head;
        while (mover->next->next != nullptr) mover = mover->next;
        ListNode* last = mover->next;
        last->next = head;
        mover->next = nullptr;
        return last;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        for (int i = 0; i < k; i++)
            head = ABCD(head);
        return head;
    }
};
//MY SOLN V2 BETTER


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        static ListNode* mover = head;
        static int size = 0;
        while (!mover) {
            mover = mover->next;
            size++;
        }
        int cut = size - (k % size);
        ListNode* mover = head;
        for (int i = 1; i < cut;i++) mover = mover->next;
        ListNode* newhead = mover->next;
        newhead->next = head;
        mover->next = nullptr;
        return head;
    }
};

//SOLN FINAL
//ONLY THIS ONE WORKS
// 65% SOLN

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head || !head->next) return head;
        
        ListNode* mover = head;
        int size = 0;
        
        while (mover!=nullptr) {
            mover = mover->next;
            size++;
        }

        if (k % size == 0)return head;
        
        int cut = size - (k % size);
        
        mover = head;
        
        for (int i = 1; i < cut;i++) mover = mover->next;

        ListNode* newhead = mover->next;
        mover->next = nullptr;
        mover = newhead;
        while (mover->next != nullptr) mover = mover->next;
        mover->next = head;
        return newhead;        
    }
};
