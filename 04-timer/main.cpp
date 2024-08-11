#include <chrono>
#include <iostream>
#include <thread>

int main(void) {
    std::cout << "Starting timer app..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto end = std::chrono::high_resolution_clock::now();

    auto diff =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Elapsed time(ms): " << diff.count() << std::endl;

    return 0;
}
