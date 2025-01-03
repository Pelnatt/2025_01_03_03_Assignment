#include <iostream>

/*
������ ������� ��ŭ �ڵ��ϼ��� ���� �����ϴ�.�� ���� �����Ͽ� �� ��Ź�帳�ϴ�.
ȥ�ڼ��� �̷��� ������ ���� �Ƿ��Դϴ�.
*/
template <typename T>
class SimpleVector {
private:
    T* data;
    int current_size;
    int max_capacity;

public:
    // �⺻ ������: ũ�Ⱑ 10�� �迭 ����
    SimpleVector() : current_size(0), max_capacity(10) {
        data = new T[max_capacity];
    }

    // ���ڸ� �ϳ� �޴� ������: �ش� ���ڿ� �ش�Ǵ� ũ���� �迭 ����
    SimpleVector(int capacity) : current_size(0), max_capacity(capacity) {
        data = new T[max_capacity];
    }

    // �Ҹ���: ���� �Ҵ�� �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: ���ڷ� ���� ���Ҹ� �� �ڿ� �߰�
    void push_back(const T& value) {
        if (current_size < max_capacity) {
            data[current_size++] = value;
        }
    }

    // pop_back: ������ ������ ���Ҹ� ����
    void pop_back() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // size: ���� ������ ������ ��ȯ
    int size() const {
        return current_size;
    }

    // capacity: ���� ���� �迭�� ũ�⸦ ��ȯ
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