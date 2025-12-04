// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* head = NULL;

// void insertAtBeginning(int value) {
//     Node* n = new Node();
//     n->data = value;
//     n->next = head;
//     head = n;
// }

// void insertAtEnd(int value) {
//     Node* n = new Node();
//     n->data = value;
//     n->next = NULL;
//     if (!head) { head = n; return; }
//     Node* t = head;
//     while (t->next) t = t->next;
//     t->next = n;
// }

// void insertBefore(int target, int value) {
//     if (!head) { cout << "List empty\n"; return; }
//     if (head->data == target) { insertAtBeginning(value); return; }
//     Node* t = head;
//     while (t->next && t->next->data != target) t = t->next;
//     if (!t->next) cout << "Node not found\n";
//     else {
//         Node* n = new Node();
//         n->data = value;
//         n->next = t->next;
//         t->next = n;
//     }
// }

// void insertAfter(int target, int value) {
//     Node* t = head;
//     while (t && t->data != target) t = t->next;
//     if (!t) cout << "Node not found\n";
//     else {
//         Node* n = new Node();
//         n->data = value;
//         n->next = t->next;
//         t->next = n;
//     }
// }

// void deleteFromBeginning() {
//     if (!head) { cout << "List empty\n"; return; }
//     Node* t = head;
//     head = head->next;
//     delete t;
// }

// void deleteFromEnd() {
//     if (!head) { cout << "List empty\n"; return; }
//     if (!head->next) { delete head; head = NULL; return; }
//     Node* t = head;
//     while (t->next->next) t = t->next;
//     delete t->next;
//     t->next = NULL;
// }

// void deleteNode(int value) {
//     if (!head) { cout << "List empty\n"; return; }
//     if (head->data == value) {
//         Node* t = head;
//         head = head->next;
//         delete t;
//         return;
//     }
//     Node* t = head;
//     while (t->next && t->next->data != value) t = t->next;
//     if (!t->next) cout << "Node not found\n";
//     else {
//         Node* d = t->next;
//         t->next = t->next->next;
//         delete d;
//     }
// }

// void searchNode(int value) {
//     Node* t = head;
//     int pos = 1;
//     while (t) {
//         if (t->data == value) { cout << "Found at position " << pos << endl; return; }
//         pos++;
//         t = t->next;
//     }
//     cout << "Not found\n";
// }

// void displayList() {
//     if (!head) { cout << "List empty\n"; return; }
//     Node* t = head;
//     while (t) {
//         cout << t->data << " -> ";
//         t = t->next;
//     }
//     cout << "NULL\n";
// }

// int deleteOccurrences(int key) {
//     int c = 0;
//     while (head && head->data == key) {
//         Node* t = head;
//         head = head->next;
//         delete t;
//         c++;
//     }
//     Node* curr = head;
//     Node* prev = NULL;
//     while (curr) {
//         if (curr->data == key) {
//             prev->next = curr->next;
//             delete curr;
//             curr = prev->next;
//             c++;
//         } else {
//             prev = curr;
//             curr = curr->next;
//         }
//     }
//     return c;
// }

// void findMiddle() {
//     if (!head) { cout << "List empty\n"; return; }
//     Node* slow = head;
//     Node* fast = head;
//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     cout << "Middle: " << slow->data << endl;
// }

// void reverseList() {
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* next;
//     while (curr) {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     head = prev;
// }

// int main() {
//     int choice, value, target, key;

//     while (true) {
//         cout << "\nMain Menu\n";
//         cout << "1. Insert at Beginning\n";
//         cout << "2. Insert at End\n";
//         cout << "3. Insert Before Node\n";
//         cout << "4. Insert After Node\n";
//         cout << "5. Delete from Beginning\n";
//         cout << "6. Delete from End\n";
//         cout << "7. Delete Specific Node\n";
//         cout << "8. Search Node\n";
//         cout << "9. Display\n";
//         cout << "10. Delete All Occurrences\n";
//         cout << "11. Find Middle\n";
//         cout << "12. Reverse List\n";
//         cout << "13. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: cin >> value; insertAtBeginning(value); break;
//             case 2: cin >> value; insertAtEnd(value); break;
//             case 3: cin >> target >> value; insertBefore(target, value); break;
//             case 4: cin >> target >> value; insertAfter(target, value); break;
//             case 5: deleteFromBeginning(); break;
//             case 6: deleteFromEnd(); break;
//             case 7: cin >> value; deleteNode(value); break;
//             case 8: cin >> value; searchNode(value); break;
//             case 9: displayList(); break;
//             case 10: cin >> key; cout << "Deleted: " << deleteOccurrences(key) << endl; break;
//             case 11: findMiddle(); break;
//             case 12: reverseList(); break;
//             case 13: return 0;
//             default: cout << "Invalid\n";
//         }
//     }
// }
