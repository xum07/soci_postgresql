/*
 * @Description: Template about singleton class
 * @Author: xum07
 * @Date: 2022-10-28
 */
#ifndef UTIL_SINGLETON
#define UTIL_SINGLETON

/**
 * @brief Singleton class whose life cycle is controlable
 */
template<typename T>
class Singleton {
public:
    Singleton(T&&) = delete;
    Singleton(const T&) = delete;
    T& operator=(const T&) = delete;
    T& operator=(T&&) = delete;

    template<typename... Args>
    static void create(Args... arg) {
        getInstRef() = new T(std::forward<Args>(arg)...);
    }

    static T* inst() {
        return getInstRef();
    }

    static void destory() {
        if (getInstRef() != nullptr) {
            delete getInstRef();
            getInstRef() = nullptr;
        }
    }

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

private:
    static T*& getInstRef() {
        static T* inst_ = nullptr;
        return inst_;
    }
};

/**
 * @brief Singleton class on stack
 */
template<typename T>
class SSingleton {
public:
    static T& inst() {
        static T obj_;
        return obj_;
    }

    SSingleton(T&&) = delete;
    SSingleton(const T&) = delete;
    T& operator=(const T&) = delete;
    T& operator=(T&&) = delete;

protected:
    SSingleton() = default;
    virtual ~SSingleton() = default;
};

#endif  // UTIL_SINGLETON