
#include <memory>
#include <iostream>

int main() {
    // Create a dynamically allocated integer with std::make_unique
    std::unique_ptr<int> myInteger = std::make_unique<int>(42);

    // Access the integer using the unique pointer
    std::cout << "The integer value is: " << *myInteger << std::endl;

    // Automatically deallocate memory when the unique pointer goes out of scope
    return 0;
}