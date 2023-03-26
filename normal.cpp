#include <iostream>
#include <cstring>

using namespace std;

const int M = 1000000; // kích thước bảng băm

struct Node {
    char key[101]; // dãy nhị phân độ dài không vượt quá 100
    int value;
};

Node table[M];

// Hàm băm đơn giản
int hashFunction(char* key) {
    int sum = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        sum += (int)key[i];
    }
    return sum % M;
}

// Thêm một khóa vào bảng băm
void put(char* key, int value) {
    int index = hashFunction(key);
    strcpy(table[index].key, key);
    table[index].value = value;
}

// Tìm kiếm giá trị tương ứng với khóa
int get(char* key) {
    int index = hashFunction(key);
    if (strcmp(table[index].key, key) == 0) {
        return table[index].value;
    } else {
        return -1;
    }
}

int main() {
    // Thêm các khóa vào bảng băm
    put("11010110", 123);
    put("01000101", 456);
    put("11100000", 789);
    put("11010110",123);
    // Tìm giá trị tương ứng với khóa
    int value1 = get("11010110"); // 123
    int value2 = get("01000101"); // 456
    int value3 = get("11100000"); // 789
    int value4 = get("10101010"); // -1
    cout << value1;
    return 0;
}
