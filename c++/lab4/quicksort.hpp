#ifndef FASTSORT_H
#define FASTSORT_H
#include <vector>

template<typename T>
void _quicksort(std::vector<T>& array, int first, int last) {
    int size = last - first;
    if(size > 1) {
        T& pivot = array[first + size / 2];
        int left = first;
        int right = last;
        while(left < right) {
            while(array[left] < pivot) {
                left++;
            }
            while(array[right] > pivot) {
                right--;
            }
            if(left <= right) {
                std::swap(array[left], array[right]);
                left++;
                right--;
            }
        }
        _quicksort(array, first, right);
        _quicksort(array, left, last);
    }
}

template<typename T>
void quicksort(std::vector<T>& array) {
    _quicksort(array, 0, array.size() - 1);
}

#endif // FASTSORT_H
