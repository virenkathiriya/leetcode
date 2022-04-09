class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int len = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index >= len) return -1;
        if (index == 0) return head -> val;
        ListNode *cur = head;
        while (index--) {
            cur = cur -> next;
        }
        return cur -> val;
    }
    
    void addAtHead(int val) {
        head = new ListNode(val, head);
        len++;
        if (head -> next == NULL) {
            tail = head;
        }
    }
    
    void addAtTail(int val) {
        if (!tail) {
            addAtHead(val);
            return;
        }
        tail -> next = new ListNode(val);
        tail = tail -> next;
        len++;
    }
    
    ListNode* getIndexPrev(int ind) {
        ListNode *cur = head;
        while (ind > 1) {
            ind--;
            cur = cur -> next;
        }
        return cur;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) return;
        if (index == len) {
            addAtTail(val);
            return;
        } 
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode* indPrev = getIndexPrev(index);
        indPrev -> next = new ListNode(val, indPrev -> next);
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= len) return;
        if (index == 0) {
            head = head -> next;
            len--;
            return;
        }
        ListNode *indPrev = getIndexPrev(index);
        indPrev -> next = indPrev -> next -> next;
        if (indPrev -> next == NULL) tail = indPrev;
        len--;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */