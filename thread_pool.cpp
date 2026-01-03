#include "thread_pool.h"

ThreadPool::ThreadPool(std::size_t thread_count)
    : stop(false)
{
    for (std::size_t i = 0; i < thread_count; ++i) {
        workers.emplace_back([this]() { worker_loop(); });
    }
}

ThreadPool::~ThreadPool() {
    stop.store(true);
    cv.notify_all();
    for (auto &t : workers) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::lock_guard<std::mutex> lock(mutex);
        tasks.push(std::move(task));
    }
    cv.notify_one();
}

void ThreadPool::worker_loop() {
    while (true) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]() {
                return stop.load() || !tasks.empty();
            });

            if (stop.load() && tasks.empty()) {
                return;
            }

            task = std::move(tasks.front());
            tasks.pop();
        }

        task();
    }
}
