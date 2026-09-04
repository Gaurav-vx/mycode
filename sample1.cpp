#include <iostream>
#include <optional>
#include <string>

// A function that might fail to find a user
std::optional<std::string> find_nickname(int user_id) {
    if (user_id == 42) {
        return "The Answer"; // Value exists
    }
    return std::nullopt;     // Value does not exist
}

int main() {
    auto user_1 = find_nickname(42);
    auto user_2 = find_nickname(99);

    // 1. Check if a value exists using operator bool
    if (user_1) {
        std::cout << "User 42 found: " << *user_1 << "\n"; // Access via * operator
    }

    // 2. Provide a safe fallback value using value_or()
    std::cout << "User 99 name: " << user_2.value_or("Guest") << "\n";

    return 0;
}

