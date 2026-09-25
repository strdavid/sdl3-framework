#include <thread>
#include <chrono>

template<typename Func>
void runAfter(Func func, int milliseconds)
{
    std::thread([func, milliseconds]() {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(milliseconds)
        );

        func();
    }).detach();
}
