/*
 * @Description: A simple thread-safty log print
 * @Author: xum07
 * @Date: 2022-10-29
 * @UpdateData: 2022-10-29
 */
#ifndef LAYOUT_DB_UTIL_LOG
#define LAYOUT_DB_UTIL_LOG

#include <iostream>
#include <mutex>

/**
 * @brief: Example: Log() << "This is a log" << std::endl;
 */
class Log final {
public:
    Log();

    template<typename T>
    Log& operator<<(const T& message)
    {
        std::cout << message;
        return *this;
    }

    Log& operator<<(std::ostream& (*fp)(std::ostream&))
    {
        std::cout << fp;
        return *this;
    }

private:
    std::lock_guard<std::mutex> lock_;
};

#endif  // LAYOUT_DB_UTIL_LOG