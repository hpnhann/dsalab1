    //STT: 18
    //Full Name: Hồ Phúc Nhân - 22520995
    //Notes or Remarks: 



// Exercise1
// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// struct Song {
//     string name;
//     Song* next;
//     Song* prev;

//     Song(string name) : name(name), next(nullptr), prev(nullptr) {}
// };

// class MusicPlayer {
// private:
//     Song* head;  // Con trỏ đến bài hát đầu tiên trong danh sách
//     Song* tail;  // Con trỏ đến bài hát cuối cùng trong danh sách
//     Song* current;  // Con trỏ đến bài hát hiện tại đang được phát
//     unordered_map<string, Song*> songMap;  // Bản đồ để tra cứu nhanh các bài hát

// public:
//     MusicPlayer() : head(nullptr), tail(nullptr), current(nullptr) {}

//     // Thêm một bài hát vào cuối danh sách phát
//     void addSong(const string& songName) {
//         Song* newSong = new Song(songName);
//         songMap[songName] = newSong;  // Lưu bài hát vào bản đồ
//         if (!head) {
//             head = tail = current = newSong;  // Nếu danh sách trống, khởi tạo head, tail và current
//         } else {
//             tail->next = newSong;  // Liên kết bài hát mới với bài hát cuối hiện tại
//             newSong->prev = tail;  // Liên kết ngược về bài hát trước đó
//             tail = newSong;  // Cập nhật tail là bài hát mới
//         }
//     }

//     // Chuyển đến bài hát tiếp theo (quay lại bài hát đầu nếu đang ở bài hát cuối)
//     void playNext() {
//         if (!current) return;
//         if (current->next) {
//             current = current->next;
//         } else {
//             current = head;  // Quay lại bài hát đầu tiên
//         }
//     }

//     // Chuyển đến bài hát trước đó (quay lại bài hát cuối nếu đang ở bài hát đầu tiên)
//     void playPrevious() {
//         if (!current) return;
//         if (current->prev) {
//             current = current->prev;
//         } else {
//             current = tail;  // Quay lại bài hát cuối cùng
//         }
//     }

//     // Xóa một bài hát theo tên khỏi danh sách phát
//     void removeSong(const string& songName) {
//         if (songMap.find(songName) == songMap.end()) return; // Nếu bài hát không tồn tại, thoát ra

//         Song* toDelete = songMap[songName];  // Tìm bài hát cần xóa
//         songMap.erase(songName);  // Xóa khỏi bản đồ

//         if (toDelete->prev) toDelete->prev->next = toDelete->next;  // Cập nhật liên kết của bài hát trước
//         if (toDelete->next) toDelete->next->prev = toDelete->prev;  // Cập nhật liên kết của bài hát sau

//         if (toDelete == head) head = toDelete->next;  // Cập nhật head nếu cần
//         if (toDelete == tail) tail = toDelete->prev;  // Cập nhật tail nếu cần
//         if (toDelete == current) current = current->next ? current->next : head;  // Cập nhật bài hát hiện tại

//         delete toDelete;  // Giải phóng bộ nhớ
//         if (!head) tail = nullptr;  // Nếu danh sách trống, đặt lại tail
//     }

//     // Hiển thị danh sách phát hiện tại và trả về dưới dạng chuỗi
//     string displayPlaylist() {
//         if (!head) {
//             return "Playlist is empty";  // Danh sách phát trống
//         }

//         Song* temp = head;
//         string result = "";
//         while (temp) {
//             result += temp->name + " ";  // Nối tên bài hát vào chuỗi kết quả
//             temp = temp->next;
//         }
//         return result;
//     }
// };

// int main() {
//     MusicPlayer player;
//     string command, songName;
//     vector<string> results;  // Lưu trữ kết quả của các thao tác DISPLAY
//     int n;

//     cout << "Nhập số lượng thao tác: ";
//     cin >> n;

//     cout << "Menu:\n";
//     cout << "1. ADD <song name> - Thêm bài hát\n";
//     cout << "2. NEXT - Phát bài hát tiếp theo\n";
//     cout << "3. PREV - Phát bài hát trước đó\n";
//     cout << "4. REMOVE <song name> - Xóa bài hát\n";
//     cout << "5. DISPLAY - Hiển thị danh sách phát\n";
//     cout << "6. EXIT - Thoát chương trình\n";

//     for (int i = 0; i < n; i++) {
//         cout << "Nhập lệnh: ";
//         cin >> command;

//         if (command == "ADD") {
//             cin >> songName;
//             player.addSong(songName);
//             cout << "Đã thêm bài hát: " << songName << endl;
//         } else if (command == "NEXT") {
//             player.playNext();
//             cout << "Đang phát bài hát tiếp theo." << endl;
//         } else if (command == "PREV") {
//             player.playPrevious();
//             cout << "Đang phát bài hát trước đó." << endl;
//         } else if (command == "REMOVE") {
//             cin >> songName;
//             player.removeSong(songName);
//             cout << "Đã xóa bài hát: " << songName << endl;
//             cout << player.displayPlaylist() << endl;  // Hiển thị danh sách bài hát còn lại
//         } else if (command == "DISPLAY") {
//             results.push_back(player.displayPlaylist());  // Lưu kết quả của DISPLAY
//         } else if (command == "EXIT") {
//             break;  // Thoát khỏi vòng lặp
//         } else {
//             cout << "Lệnh không hợp lệ. Vui lòng thử lại." << endl;
//         }
//     }

//     // In ra tất cả kết quả của DISPLAY một lần sau khi thực hiện xong các thao tác
//     for (const string& result : results) {
//         cout << result << endl;
//     }

//     return 0;
// }





// Exercise2
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// class BrowserHistory {
// private:
//     vector<string> history;  // Danh sách lưu trữ lịch sử duyệt web
//     int currentIndex;        // Chỉ số của trang hiện tại

// public:
//     // Khởi tạo với trang chủ
//     BrowserHistory(string homepage) {
//         if (homepage.length() < 1 || homepage.length() > 20) {
//             throw invalid_argument("Homepage phải có độ dài từ 1 đến 20 ký tự.");
//         }
//         history.push_back(homepage);
//         currentIndex = 0;
//     }

//     // Truy cập URL mới
//     void visit(string url) {
//         // Kiểm tra độ dài của URL
//         if (url.length() < 1 || url.length() > 20) {
//             throw invalid_argument("URL phải có độ dài từ 1 đến 20 ký tự.");
//         }
//         // Xóa lịch sử phía trước nếu có khi truy cập URL mới
//         history.erase(history.begin() + currentIndex + 1, history.end());
//         history.push_back(url);
//         currentIndex++;
//     }

//     // Quay lại một số bước (back)
//     string back(int steps) {
//         // Giới hạn số bước không quá 100
//         steps = min(steps, 100);
//         // Di chuyển lùi nhưng không vượt quá chỉ số 0
//         currentIndex = max(0, currentIndex - steps);
//         return history[currentIndex];  // Trả về URL hiện tại
//     }

//     // Tiến về phía trước một số bước (forward)
//     string forward(int steps) {
//         // Giới hạn số bước không quá 100
//         steps = min(steps, 100);
//         // Di chuyển tiến lên nhưng không vượt quá số phần tử trong lịch sử
//         currentIndex = min((int)history.size() - 1, currentIndex + steps);
//         return history[currentIndex];  // Trả về URL hiện tại
//     }

//     // Hiển thị URL hiện tại
//     string getCurrentUrl() {
//         return history[currentIndex];
//     }
// };

// int main() {
//     try {
//         string homepage;
//         cout << "Nhập trang chủ (homepage): ";
//         cin >> homepage;

//         BrowserHistory browserHistory(homepage);

//         int choice;
//         do {
//             cout << "\n--- Trình duyệt ---\n";
//             cout << "1. Visit URL\n";
//             cout << "2. Back\n";
//             cout << "3. Forward\n";
//             cout << "4. Hiển thị URL hiện tại\n";
//             cout << "5. Thoát\n";
//             cout << "Chọn hành động (1-5): ";
//             cin >> choice;

//             if (choice == 1) {
//                 string url;
//                 cout << "Nhập URL để truy cập: ";
//                 cin >> url;
//                 browserHistory.visit(url);
//                 cout << "Truy cập: " << browserHistory.getCurrentUrl() << endl;
//             } 
//             else if (choice == 2) {
//                 int steps;
//                 cout << "Nhập số bước muốn quay lại: ";
//                 cin >> steps;
//                 cout << "Đã quay lại: " << browserHistory.back(steps) << endl;
//             } 
//             else if (choice == 3) {
//                 int steps;
//                 cout << "Nhập số bước muốn tiến tới: ";
//                 cin >> steps;
//                 cout << "Đã tiến tới: " << browserHistory.forward(steps) << endl;
//             } 
//             else if (choice == 4) {
//                 cout << "URL hiện tại: " << browserHistory.getCurrentUrl() << endl;
//             }

//         } while (choice != 5);  // Thoát khi người dùng chọn 5

//         cout << "Đã thoát chương trình." << endl;
//     } catch (const invalid_argument& e) {
//         cout << e.what() << endl;
//     }

//     return 0;
// }





// Exercise3
// #include <iostream>
// #include <unordered_map>
// #include <string>

// class AuthenticationManager {
// private:
//     int timeToLive; // Thời gian sống của mã thông báo
//     std::unordered_map<std::string, int> tokens; // Bảng băm lưu mã thông báo và thời gian hết hạn

// public:
//     // Constructor
//     AuthenticationManager(int timeToLive) {
//         // Kiểm tra ràng buộc của timeToLive
//         if (timeToLive < 1 || timeToLive > 100000000) {
//             throw std::out_of_range("Thời gian sống phải nằm trong khoảng từ 1 đến 10^8.");
//         }
//         this->timeToLive = timeToLive;
//     }

//     // Phương thức tạo mã thông báo
//     void generate(const std::string& tokenId, int currentTime) {
//         // Kiểm tra độ dài tokenId
//         if (tokenId.length() > 5 || !isLowercase(tokenId)) {
//             throw std::invalid_argument("tokenId phải có độ dài tối đa là 5 ký tự và chỉ chứa chữ cái thường.");
//         }
        
//         // Tính toán thời gian hết hạn
//         int expiryTime = currentTime + timeToLive;
//         // Thêm mã thông báo vào bảng băm
//         tokens[tokenId] = expiryTime;
//     }

//     // Phương thức gia hạn mã thông báo
//     void renew(const std::string& tokenId, int currentTime) {
//         // Kiểm tra xem mã thông báo có còn hiệu lực không
//         if (tokens.count(tokenId) && tokens[tokenId] > currentTime) {
//             // Gia hạn thời gian sống của mã thông báo
//             int expiryTime = currentTime + timeToLive;
//             tokens[tokenId] = expiryTime;
//         }
//     }

//     // Phương thức đếm mã thông báo còn hiệu lực
//     int countUnexpiredTokens(int currentTime) {
//         int count = 0;
//         for (const auto& token : tokens) {
//             // Kiểm tra xem mã thông báo có còn hiệu lực không
//             if (token.second > currentTime) {
//                 count++;
//             }
//         }
//         return count;
//     }

// private:
//     // Phương thức kiểm tra xem chuỗi có chứa chỉ chữ cái thường hay không
//     bool isLowercase(const std::string& str) {
//         for (char c : str) {
//             if (!std::islower(c)) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// // Ví dụ sử dụng lớp AuthenticationManager
// int main() {
//     int timeToLive;
//     std::cout << "Nhập thời gian sống (timeToLive) cho mã thông báo (1 đến 10^8): ";
//     std::cin >> timeToLive;

//     AuthenticationManager authManager(timeToLive); // Khởi tạo với thời gian sống từ input

//     while (true) {
//         std::string command;
//         std::cout << "Nhập lệnh (generate/renew/count/exit): ";
//         std::cin >> command;

//         if (command == "generate") {
//             std::string tokenId;
//             int currentTime;
//             std::cout << "Nhập tokenId (tối đa 5 ký tự): ";
//             std::cin >> tokenId;
//             std::cout << "Nhập currentTime: ";
//             std::cin >> currentTime;

//             try {
//                 authManager.generate(tokenId, currentTime);
//                 std::cout << "Mã thông báo \"" << tokenId << "\" đã được tạo.\n";
//             } catch (const std::exception& e) {
//                 std::cout << "Lỗi: " << e.what() << "\n";
//             }
//         } 
//         else if (command == "renew") {
//             std::string tokenId;
//             int currentTime;
//             std::cout << "Nhập tokenId để gia hạn: ";
//             std::cin >> tokenId;
//             std::cout << "Nhập currentTime: ";
//             std::cin >> currentTime;

//             authManager.renew(tokenId, currentTime);
//             std::cout << "Mã thông báo \"" << tokenId << "\" đã được gia hạn (nếu còn hiệu lực).\n";
//         } 
//         else if (command == "count") {
//             int currentTime;
//             std::cout << "Nhập currentTime để đếm mã thông báo: ";
//             std::cin >> currentTime;

//             int count = authManager.countUnexpiredTokens(currentTime);
//             std::cout << "Số mã thông báo còn hiệu lực: " << count << "\n";
//         } 
//         else if (command == "exit") {
//             break;
//         } 
//         else {
//             std::cout << "Lệnh không hợp lệ. Vui lòng thử lại.\n";
//         }
//     }
    
//     return 0;
// }
