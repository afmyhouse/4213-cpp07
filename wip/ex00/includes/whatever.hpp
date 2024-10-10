#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T1, typename T2>
struct IsSameType {
    static const bool value = false;
};

template <typename T>
struct IsSameType<T, T> {
    static const bool value = true;
};

template <typename T>
void swap(T &a, T &b)
{
    if (IsSameType<T, T>::value) {
    T tmp = a;
	a = b;
	b = tmp;
    } else {
        std::cout << "Types are not the same. Swap is not performed.\n";
    }
}

template <typename T>
T max(T a, T b)
{
    if (IsSameType<T, T>::value) {
        return (a > b ? a : b);
    } else {
        std::cout << "Types are not the same. compare is not performed.\n";
    }
}

template <typename T>
T min(T a, T b)
{
    if (IsSameType<T, T>::value) {
        return (a < b ? a : b);
    } else {
        std::cout << "Types are not the same. compare is not performed.\n";
    }
}

#endif
