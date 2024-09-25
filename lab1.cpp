#include <iostream>
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



// #include <iostream>
// #include <unordered_set>
// using namespace std;

// // Định nghĩa Node cho danh sách liên kết đơn
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// // Hàm phát hiện chu kỳ trong danh sách liên kết
// bool detectCycle(ListNode* head) {
//     unordered_set<ListNode*> nodeSet;  // Tập hợp để lưu trữ các node đã duyệt

//     ListNode* current = head;

//     // Duyệt qua danh sách liên kết
//     while (current != nullptr) {
//         // Nếu node đã tồn tại trong tập hợp, có chu kỳ
//         if (nodeSet.find(current) != nodeSet.end()) {
//             return true;
//         }

//         // Nếu chưa gặp node này, thêm nó vào tập hợp
//         nodeSet.insert(current);

//         // Chuyển sang node tiếp theo
//         current = current->next;
//     }

//     // Nếu không có chu kỳ
//     return false;
// }

// // Hàm tạo danh sách liên kết từ đầu vào của người dùng
// ListNode* createList(int n) {
//     if (n <= 0) return nullptr;

//     int value;
//     cout << "Nhập giá trị cho node 1: ";
//     cin >> value;

//     ListNode* head = new ListNode(value);
//     ListNode* current = head;

//     // Nhập giá trị cho các node còn lại
//     for (int i = 2; i <= n; i++) {
//         cout << "Nhập giá trị cho node " << i << ": ";
//         cin >> value;
//         current->next = new ListNode(value);
//         current = current->next;
//     }

//     return head;
// }

// // Hàm phụ để tạo một chu kỳ trong danh sách liên kết
// void createCycle(ListNode* head, int pos, int n) {
//     if (head == nullptr || pos < 0 || pos >= n) return;

//     ListNode* cycleNode = nullptr;
//     ListNode* temp = head;
//     int index = 0;

//     // Duyệt đến vị trí của chu kỳ
//     while (temp->next != nullptr) {
//         if (index == pos) {
//             cycleNode = temp;
//         }
//         temp = temp->next;
//         index++;
//     }

//     // Tạo chu kỳ bằng cách trỏ node cuối về vị trí `pos`
//     if (cycleNode != nullptr) {
//         temp->next = cycleNode;
//     }
// }

// int main() {
//     int n, cyclePos;

//     // Nhập số lượng phần tử trong danh sách
//     cout << "Nhập số lượng phần tử trong danh sách liên kết: ";
//     cin >> n;

//     // Tạo danh sách liên kết
//     ListNode* head = createList(n);

//     // Nhập vị trí tạo chu kỳ (-1 nếu không muốn tạo chu kỳ)
//     cout << "Nhập vị trí để tạo chu kỳ (tính từ 0, nhập -1 nếu không tạo chu kỳ): ";
//     cin >> cyclePos;

//     // Tạo chu kỳ nếu cần
//     if (cyclePos != -1) {
//         createCycle(head, cyclePos, n);
//     }

//     // Kiểm tra chu kỳ sau khi tạo chu kỳ
//     if (detectCycle(head)) {
//         cout << "Danh sách liên kết có chu kỳ." << endl;
//     } else {
//         cout << "Danh sách liên kết không có chu kỳ." << endl;
//     }

//     return 0;
// }