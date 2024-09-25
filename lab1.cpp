using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int countNodes(ListNode*head){
    int count = 0;
    ListNode*current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

ListNode* findmiddlenode (ListNode* head){
    if (head == nullptr ) return nullptr;
    int totalNodes = countNodes(head);
    int middleIndex = totalNodes / 2;
    ListNode* current = head;
    for (int i = 0; i < middleIndex; ++i){
        current = current->next;
    }

    return current;

}

void printList(ListNode*node){
    while (node != nullptr){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
void appendNode (ListNode*& head, int value){
    if (head == nullptr){
        head = new ListNode(value);
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new ListNode(value);
}
int main(){
    ListNode*head = nullptr;
    for (int i = 1; i<=5; ++i){
        appendNode(head, i);
    }
    cout << "Danh sach ban dau: ";
    printList(head);

    ListNode* middle = findmiddlenode(head);
    if (middle != nullptr) {
        cout << "Gia tri node giua: "  << middle->val << endl;
    }
    else {
        cout << "Danh sach rong: " << endl;
    } 
    return 0;
}