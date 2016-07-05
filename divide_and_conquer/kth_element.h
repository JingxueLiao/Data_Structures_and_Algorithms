#pragma once

#include <stdexcept>

template <typename T>
T kth_element(T *first, T *last, int k) {
    int n = last - first;
    if (k <= 0 || k > n)
        throw std::invalid_argument("invalid arguments");
    T *p = first, *q = last - 1;
    T pivot = *p;
    while (p != q) {
        while (p != q && pivot < *q)
            --q;
        *p = *q;
        while (p != q && *p < pivot)
            ++p;
        *q = *p;
    }
    *p = pivot;
    int index = p - first + 1;
    if (index < k)
        return kth_element(p + 1, last, k - index);
    else if (k < index)
        return kth_element(first, p, k);
    else
        return *p;
}
