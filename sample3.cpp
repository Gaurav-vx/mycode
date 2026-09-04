#include <iostream>
#include <utility> // for std::move

class DynamicArray {
public:
    int* data;
    size_t size;

    // 1. Regular Constructor
    DynamicArray(size_t s) : size(s), data(new int[s]) {}

    // 2. Destructor
    ~DynamicArray() { delete[] data; }

    // 3. COPY CONSTRUCTOR (Expensive)
    DynamicArray(const DynamicArray& other) : size(other.size), data(new int[other.size]) {
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i]; // Deep copy
        std::cout << "Copy Constructor Called (Slow)\n";
    }

    // 4. MOVE CONSTRUCTOR (Fast & Efficient)
    // Takes an rvalue reference (&&) and must be noexcept for STL optimization
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        // Steal resources: data pointer now points to other's memory

        // Clean up source object so its destructor doesn't free our new memory
        other.data = nullptr; 
        other.size = 0;
        std::cout << "Move Constructor Called (Fast)\n";
    }
};

int main() {
    DynamicArray arr1(10000); 
    
    // std::move casts arr1 into an rvalue, forcing the move constructor
    DynamicArray arr2 = std::move(arr1); 

    // arr2 now owns the 10000 integers. arr1.data is now nullptr.
    return 0;
}

