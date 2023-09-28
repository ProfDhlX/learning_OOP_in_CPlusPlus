//C++ program using object and class to short an array of string in order
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class StringSorter {
public:
    StringSorter(int size) : size_(size) {
        array_ = new string[size_];
    }

    ~StringSorter() {
        delete[] array_;
    }

    void inputStrings() {
        cout << "Enter " << size_ << " strings:" << endl;
        for (int i = 0; i < size_; ++i) {
            cin >> array_[i];
        }
    }

    void sortStrings() {
        sort(array_, array_ + size_);
    }

    void displaySortedStrings() {
        cout << "Sorted strings:" << endl;
        for (int i = 0; i < size_; ++i) {
            cout << array_[i] << endl;
        }
    }

private:
    int size_;
    string* array_;
};

int main() {
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;

    StringSorter obj(size);
    obj.inputStrings();
    obj.sortStrings();
    obj.displaySortedStrings();

    return 0;
}

