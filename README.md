# cpp-thread-pool

Simple C++11 thread pool for running multiple tasks in parallel using a fixed set of worker threads.

The goal of this project is to demonstrate:
- modern C++ (C++11 and above)
- basic multithreading
- synchronization with mutex and condition_variable
- simple task scheduling design

## Features

- fixed number of worker threads
- task queue based on std::queue and std::function
- safe shutdown of all threads in destructor
- minimal and clear API: enqueue a lambda or callable

## Project structure

thread_pool.h - thread pool class declaration  
thread_pool.cpp - thread pool implementation  
main.cpp - usage example and simple test scenario  

## Build (Linux / macOS)

Use any modern C++ compiler that supports C++17.

Example build command:

g++ -std=c++17 -O2 -pthread main.cpp thread_pool.cpp -o thread_pool_demo

## Run

After successful build:

./thread_pool_demo

You will see several tasks executed in parallel by different threads.

## Example use cases

- educational example of how thread pools work  
- base for parallel execution of CPU heavy tasks  
- demonstration of multithreading skills for C++ job applications  

## Disclaimer

This project is intended for educational and research purposes only.
The author is not responsible for any misuse of the code.
