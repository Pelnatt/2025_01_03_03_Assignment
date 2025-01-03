#include <iostream>

/*
과제가 어려웠던 만큼 자동완성에 많이 기댔습니다.그 점도 유의하여 평가 부탁드립니다.
혼자서는 이렇게 만들지 못할 실력입니다.
*/
template <typename T>
class SimpleVector {
private:
    T* data;
    int current_size;
    int max_capacity;

public:
    // 기본 생성자: 크기가 10인 배열 생성
    SimpleVector() : current_size(0), max_capacity(10) {
        data = new T[max_capacity];
    }

    // 숫자를 하나 받는 생성자: 해당 숫자에 해당되는 크기의 배열 생성
    SimpleVector(int capacity) : current_size(0), max_capacity(capacity) {
        data = new T[max_capacity];
    }

    // 소멸자: 동적 할당된 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 인자로 받은 원소를 맨 뒤에 추가
    void push_back(const T& value) {
        if (current_size < max_capacity) {
            data[current_size++] = value;
        }
    }

    // pop_back: 벡터의 마지막 원소를 제거
    void pop_back() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // size: 현재 원소의 개수를 반환
    int size() const {
        return current_size;
    }

    // capacity: 현재 내부 배열의 크기를 반환
    int capacity() const {
        return max_capacity;
    }
};

int main() {
    SimpleVector<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Size: " << vec.size() << std::endl; // Size: 3
    std::cout << "Capacity: " << vec.capacity() << std::endl; // Capacity: 5

    vec.pop_back();
    std::cout << "Size after pop_back: " << vec.size() << std::endl; // Size after pop_back: 2

    return 0;
}