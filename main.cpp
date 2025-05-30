#include <iostream>
#include <android/log.h>

int main() {
    __android_log_print(ANDROID_LOG_INFO, "NDKTest", "Hello from NDK!");
    std::cout << "Hello from NDK (std::cout)!" << std::endl;
    return 0;
}
