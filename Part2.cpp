
// //STT: 18
// //Full name: Hồ Phúc Nhân - 22520995
// //Session 01 - Exercise - Part 02
// //Notes or Remarks:


#include <iostream>
#include <vector>
#include <cstdlib> // For rand()

using namespace std;

void showMenu() {
    cout << "1. Add Two Numbers\n";
    cout << "2. Copy List with Random Pointers\n";
    cout << "3. Swap Nodes in a Linked List\n";
    cout << "4. Remove the N-th Node from the End of a List\n";
    cout << "5. Separate Odd and Even Nodes in a Linked List\n";
    cout << "6. Divide a Linked List into Parts\n";
    cout << "7. Remove Zero-Sum Consecutive Nodes from a Linked List\n";
    cout << "8. Randomly Generate a List\n";
    cout << "0. Exit\n";
}

struct Node {
    int value;
    Node* next;
    Node* random;
    
    Node(int val) : value(val), next(nullptr), random(nullptr) {}
};

struct List {
    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr) {}

    void addTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printList() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* tmp = head;
        while (tmp) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int countNodes(const List& list) {
    Node* tmp = list.head;
    int count = 0;
    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void deleteNthNode(List& list, int n) {
    if (n < 1 || countNodes(list) < n) {
        cout << "Invalid position.\n";
        return;
    }

    Node* tmp = list.head;
    if (n == 1) {
        list.head = tmp->next;
        if (!list.head) {
            list.tail = nullptr;
        }
        delete tmp;
        return;
    }

    Node* prev = nullptr;
    for (int i = 1; i < n; ++i) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp->next;
    if (!prev->next) {
        list.tail = prev;
    }
    delete tmp;
}

void deleteNthFromEnd(List& list, int n) {
    int totalNodes = countNodes(list);
    deleteNthNode(list, totalNodes - n + 1);
}

List separateOddAndEven(const List& list) {
    List result;
    Node* tmp = list.head;
    while (tmp) {
        if (tmp->value % 2 == 0) {
            result.addHead(tmp->value);
        } else {
            result.addTail(tmp->value);
        }
        tmp = tmp->next;
    }
    return result;
}

void swapNodes(List& list, int pos1, int pos2) {
    if (pos1 == pos2 || !list.head) return;

    Node* prev1 = nullptr, * prev2 = nullptr;
    Node* node1 = list.head, * node2 = list.head;

    for (int i = 1; i < pos1; ++i) {
        prev1 = node1;
        node1 = node1->next;
    }
    for (int i = 1; i < pos2; ++i) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (!node1 || !node2) return;

    if (prev1) prev1->next = node2;
    else list.head = node2;

    if (prev2) prev2->next = node1;
    else list.head = node1;

    swap(node1->next, node2->next);

    if (!node1->next) list.tail = node1;
    if (!node2->next) list.tail = node2;
}

void removeZeroSumNodes(List& list) {
    if (!list.head) return;

    Node* dummy = new Node(0);
    dummy->next = list.head;
    Node* current = dummy;
    int sum = 0;

    while (current->next) {
        sum += current->next->value;
        if (sum == 0) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    list.head = dummy->next;
    delete dummy;
}

void divideList(List& list, int k) {
    int totalNodes = countNodes(list);
    int partSize = totalNodes / k;
    int remainder = totalNodes % k;

    Node* current = list.head;
    for (int i = 0; i < k; ++i) {
        int currentPartSize = partSize + (i < remainder ? 1 : 0);
        cout << "Part " << i + 1 << ": ";
        for (int j = 0; j < currentPartSize && current; ++j) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
}

Node* copyListWithRandom(Node* head) {
    if (!head) return nullptr;

    // Duplicate each node
    for (Node* current = head; current; current = current->next->next) {
        Node* copy = new Node(current->value);
        copy->next = current->next;
        current->next = copy;
    }

    // Assign random pointers to duplicates
    for (Node* current = head; current; current = current->next->next) {
        if (current->random) {
            current->next->random = current->random->next;
        }
    }

    // Separate the original list and the copy
    Node* newHead = head->next;
    Node* original = head;
    Node* copy = newHead;

    while (original && copy) {
        original->next = copy->next;
        original = original->next;

        if (original) {
            copy->next = original->next;
        }
        copy = copy->next;
    }

    return newHead;
}

void randomlyGenerateList(List& list) {
    int numNodes = rand() % 21 + 39; // Random between 39 and 59
    for (int i = 0; i < numNodes; ++i) {
        list.addTail(rand() % 199 - 99); // Random between -99 and 99
    }
    list.printList();
}

void Prob1(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    cout<<endl<<"You're about to add 2 numbers to the list above.";
    cout<<endl<<"Enter the 1st number: "; cin>>n;
    A.addTail(n);
    cout<<"Enter the 2nd number: "; cin>>n;
    A.addTail(n);
    cout<<endl<<"Your final list: ";
    A.printList(); cout<<endl;
}
void Prob2(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    List B;
    Node* randomHeadNode = copyListWithRandPointers(A.head);
    B.head = randomHeadNode;
    cout<<endl;
    B.printList();
    cout<<endl;
}
void Prob3(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    cout<<endl;
    swapNodes(A);
    A.printList();
    cout<<endl;
}
void Prob4(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    cout<<endl<<"Enter the position of the node you wish to delete: "; 
    cin>>n;
    deleteNodeNFromTheEnd(A,n);
    A.printList();
    cout<<endl;
}
void Prob5(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    List B = sortedOddAndEvenList(A);
    cout<<endl;
    B.printList();
    cout<<endl;
}
void Prob6(){
    List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    cout<<endl<<"How many parts do you want to divide into?"; 
    cout<<endl;
    cin>>n;
    divideList(A,n);
}
void Prob7(){
   List A;
    cout<<"Initialize your list."<<endl;
    int n;
    cout<<"Enter the values: "<<endl;
    while(1){
        cin>>n;
        if (n==0) break;
        A.addTail(n);
    }
    A.printList();
    removeZeroSumNodes(A);
    cout<<endl;
    A.printList();
    cout<<endl;
}
void Prob8(){
    //Su dung ham rand() tu thu vien cstdlib de lay random gia tri
    //So luong node/entry
    int numbOfEntries = rand() % 21 + 39; //lay random trong khoang 39-59
    List A;
    //Loop n lan de them tung node vao, voi moi node assign random value trong khoang -99 den 99
    int value;
    for (int i = 1; i < numbOfEntries; i++){
        value = rand() % 199 - 99;
        A.addTail(value);
    }
    A.printList();
    cout<<endl;
}


int main(){
    while(1){
        showMenu();
        int n;
        cin>>n;
        switch (n){
            case 0:
                return 0;
            case 1:
                Prob1();
                break;
            case 2:
                Prob2();
                break;
            case 3:
                Prob3();
                break;
            case 4:
                Prob4();
                break;
            case 5:
                Prob5();
                break;
            case 6:
                Prob6();
                break;
            case 7:
                Prob7();
                break;
            case 8:
                Prob8();
                break;
            default:
                cout<<"Retry.";
                break;
        }
    }
    return 0;
}
