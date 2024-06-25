#include <iostream>
using namespace std;

template <typename T> class Vector {

private:

    T* arr;
    int capacity;
    int current;

public:

    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    ~Vector() { delete[] arr;}


    void push_back(T data) {

        if (current == capacity) {

            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {temp[i] = arr[i];}
            delete[] arr;

            capacity *= 2;
            arr = temp;

        }

        arr[current] = data;
        current++;

    }


    void insert(int index, T data) {
        if (index == current) {
            push_back(data);
        } else {
            arr[index] = data;
        }
    }


    void pop_back() {
        if (current > 0) {
            current--;
        }
    }


    int size() const {
        return current;
    }


    T get(int index) const {
        if (index < current) {
            return arr[index];
        }
        return -1;
    }


    T& operator[](int index) {
        if (index < current) {
            return arr[index];
        }
        throw out_of_range("Index out of range");
    }

    void print(){
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;        
    }

};

int main() {
    
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    cout << "Vector size: " << vec.size() << endl;

    cout << "Vector elements: ";
    vec.print();

    vec.pop_back();

    cout << "Vector elements after pop_back: ";
    vec.print();

    vec.insert(2, 100);

    cout << "Vector elements after insert: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
