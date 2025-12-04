#include <iostream>
using namespace std;


// QUES 1 (a)  -> DOUBLY LINKED LIST (MENU DRIVEN)


struct DNode {
    int data;
    DNode *next, *prev;
};

DNode *Dhead = NULL;

void D_insertBegin() {
    int x;
    cin >> x;
    DNode *n = new DNode{x, Dhead, NULL};
    if (Dhead != NULL) Dhead->prev = n;
    Dhead = n;
}

void D_insertEnd() {
    int x;
    cin >> x;
    DNode *n = new DNode{x, NULL, NULL};
    if (!Dhead) { Dhead = n; return; }
    DNode *t = Dhead;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void D_insertAfter() {
    int val, x;
    cin >> val >> x;
    DNode *t = Dhead;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    DNode *n = new DNode{x, t->next, t};
    if (t->next) t->next->prev = n;
    t->next = n;
}

void D_insertBefore() {
    int val, x;
    cin >> val >> x;
    if (!Dhead) return;
    if (Dhead->data == val) { D_insertBegin(); return; }
    DNode *t = Dhead;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    DNode *n = new DNode{x, t, t->prev};
    t->prev->next = n;
    t->prev = n;
}

void D_deleteNode() {
    int val;
    cin >> val;
    DNode *t = Dhead;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else Dhead = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

void D_search() {
    int val, pos = 1;
    cin >> val;
    DNode *t = Dhead;
    while (t) {
        if (t->data == val) { cout << pos << endl; return; }
        pos++; t = t->next;
    }
    cout << "-1\n";
}

void D_display() {
    DNode *t = Dhead;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;
}





// QUES 1 (b) -> CIRCULAR LINKED LIST (MENU DRIVEN)


struct CNode {
    int data;
    CNode *next;
};

CNode *Chead = NULL;

void C_insertBegin() {
    int x;
    cin >> x;
    CNode *n = new CNode{x, NULL};

    if (!Chead) { Chead = n; n->next = Chead; return; }

    CNode *t = Chead;
    while (t->next != Chead) t = t->next;
    n->next = Chead;
    t->next = n;
    Chead = n;
}

void C_insertEnd() {
    int x;
    cin >> x;
    CNode *n = new CNode{x, NULL};

    if (!Chead) { Chead = n; n->next = Chead; return; }

    CNode *t = Chead;
    while (t->next != Chead) t = t->next;
    t->next = n;
    n->next = Chead;
}

void C_deleteNode() {
    int val;
    cin >> val;
    if (!Chead) return;

    CNode *t = Chead, *prev = NULL;

    if (Chead->data == val) {
        while (t->next != Chead) t = t->next;
        if (t == Chead) { delete Chead; Chead = NULL; return; }
        t->next = Chead->next;
        delete Chead;
        Chead = t->next;
        return;
    }

    prev = Chead;
    t = Chead->next;

    while (t != Chead && t->data != val) { prev = t; t = t->next; }

    if (t == Chead) return;

    prev->next = t->next;
    delete t;
}

void C_searchNode() {
    int val, pos = 1;
    cin >> val;

    if (!Chead) return;
    CNode *t = Chead;
    do {
        if (t->data == val) { cout << pos << endl; return; }
        pos++; t = t->next;
    } while (t != Chead);
    cout << "-1\n";
}

void C_display() {
    if (!Chead) { cout << "Empty\n"; return; }
    CNode *t = Chead;
    do { cout << t->data << " "; t = t->next; }
    while (t != Chead);
    cout << endl;
}





// QUES 2 -> Circular Print with Repeat


struct Node2 {
    int data;
    Node2 *next;
};

Node2 *Q2_head = NULL;

void Q2_insert(int v) {
    Node2 *n = new Node2{v, NULL};
    if (!Q2_head) { Q2_head = n; n->next = Q2_head; return; }
    Node2 *t = Q2_head;
    while (t->next != Q2_head) t = t->next;
    t->next = n;
    n->next = Q2_head;
}

void Q2_display() {
    if (!Q2_head) return;
    Node2 *t = Q2_head;
    do { cout << t->data << " "; t = t->next; }
    while (t != Q2_head);
    cout << Q2_head->data << endl;
}





// QUES 3 (a) -> Size of Doubly LL


struct D2Node {
    int data;
    D2Node *prev, *next;
};

D2Node* Q3a_insert(D2Node* head, int data) {
    D2Node* n = new D2Node();
    n->data = data;
    n->prev = n->next = NULL;
    if (!head) return n;
    D2Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

int Q3a_size(D2Node* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}





// QUES 3 (b) -> Size of Circular LL


struct C2Node {
    int data;
    C2Node *next;
};

C2Node* Q3b_insert(C2Node* head, int d) {
    C2Node* n = new C2Node();
    n->data = d;
    if (!head) { n->next = n; return n; }
    C2Node* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
    return head;
}

int Q3b_size(C2Node* head) {
    if (!head) return 0;
    int c = 0;
    C2Node* t = head;
    do { c++; t = t->next; }
    while (t != head);
    return c;
}





// QUES 4 -> Palindrome (Doubly LL)


struct PNode {
    char data;
    PNode *next, *prev;
};

PNode* Phead = NULL;

void P_insert(char x) {
    PNode* n = new PNode{x, NULL, NULL};
    if (!Phead) { Phead = n; return; }
    PNode* t = Phead;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

bool isPalindrome() {
    if (!Phead || !Phead->next) return true;
    PNode *l = Phead, *r = Phead;
    while (r->next) r = r->next;
    while (l != r && r->next != l) {
        if (l->data != r->data) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}





// QUES 5 -> Check Circular


struct Node5 {
    int data;
    Node5 *next;
};

bool isCircular(Node5* head) {
    if (!head) return false;
    Node5* t = head->next;
    while (t && t != head) t = t->next;
    return (t == head);
}






// MAIN PROGRAM


int main() {

    // All functions present above.
    // You can call any part separately for testing.
    
    cout << "ALL QUESTIONS COMBINED SUCCESSFULLY.\n";
    cout << "Run individual parts by calling their functions.\n";

    return 0;
}
