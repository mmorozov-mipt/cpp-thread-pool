#include <iostream>
#include <chrono>
#include <thread>
#include "thread_pool.h"

int main() {
    ThreadPool pool(4);

    std::cout << "Submitting tasks to thread pool...\n";

    for (int i = 0; i < 10; ++i) {
        int task_id = i;
        pool.enqueue([task_id]() {
            std::cout << "Task " << task_id << " started on thread "
                      << std::this_thread::get_id() << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout << "Task " << task_id << " finished\n";
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Main thread finished\n";
    return 0;
}
