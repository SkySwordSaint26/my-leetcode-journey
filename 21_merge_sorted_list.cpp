#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* mergedHead = nullptr;
    
    if (l1->val < l2->val) {
        mergedHead = l1;
        l1 = l1->next;
    }
    else {
        mergedHead = l2;
        l2 = l2->next;
    }
    ListNode* current = mergedHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1) {
        current->next = l1;
    }
    else if (l2) {
        current->next = l2;
    }
    return mergedHead;
}

int main() {
    // Example usage:   
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Print merged list
    ListNode* current = mergedList;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    // Clean up memory
    current = mergedList;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }   
    return 0;
}