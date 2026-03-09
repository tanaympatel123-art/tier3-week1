#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void worker(int id) {
    std::cout << "Thread " << id << " starting...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Thread " << id << " finished.\n";
}

int main() {
    std::cout << "Main: Launching 5 threads...\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Main: All 5 threads complete! ✅\n";
    return 0;
}