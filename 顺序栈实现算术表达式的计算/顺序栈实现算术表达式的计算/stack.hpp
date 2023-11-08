#pragma once
#include <iostream>

template <typename T>
class stack {
private:
    int size;
    T* data;
    int top;

public:
    stack(int df = 30) : size(df) {
        data = new T[df];
        top = -1;
    }

    ~stack() {
        delete[] data;
    }

    void expansion() {
        if (size == top + 1) {
            T* newdata = new T[size * 2];
            for (int i = 0; i < size; i++) {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            size *= 2;
        }
    }

    void push_back(T a) {
        expansion();
        data[top+1] = a;
        top = top + 1;
    }

    T pop() {
        if (!isempty()) {
            top--;
            return data[top+1];
            
        }
        std::cerr << "Stack is empty" << std::endl;
        return T();  // Return a default-constructed value for the type T (e.g., 0 for int)
    }

    bool isempty() {
        return top == -1;
    }

    T* getarray() {
        return data;
    }

    T gettop() {
        if (!isempty()) {
            return data[top];
        }
        else {
            return T();  // Return a default-constructed value for the type T
        }
    }

    int getsize() {
        return top + 1;
    }
};
