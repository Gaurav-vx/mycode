#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter{0};

void work() {
    for (int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    std::cout << counter << '\n';  // 2000
}

