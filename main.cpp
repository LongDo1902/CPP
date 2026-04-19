#include <initializer_list>
#include <iostream>
#include <stdio.h>

class fraction_t {
  public:
    int num;
    int den;
};

template <typename T> class array_fixed {
  public:
    T  *array_memory;
    int num_elements;

    array_fixed(int size) : num_elements(size)
    {
        array_memory = (T *)malloc(num_elements * sizeof(T));
    }

    array_fixed(std::initializer_list<T> init_list)
    {
        array_memory = (T *)malloc(init_list.size() * sizeof(T));
        num_elements = init_list.size();

        int i = 0;
        for (auto list : init_list) {
            array_memory[i++] = list;
        }
    }

    // To use foreach, our class has to enable begin() and end()
    // begin() return the first address
    // end() return the last address
    T *
    begin()
    {
        return &array_memory[0];
    }

    T *
    end()
    {
        return &array_memory[num_elements];
    }

    T &
    operator[](int idx)
    {
        return array_memory[idx];
    }

    ~array_fixed()
    {
        if (array_memory != nullptr) {
            free(array_memory);
            array_memory = nullptr;
        }
    }

    // Disable copying
    array_fixed(const array_fixed &)            = delete;
    array_fixed &operator=(const array_fixed &) = delete;
};

bool
compare_fraction(const fraction_t &A, const fraction_t &B)
{
    // Convert to decimal before comparing
    return ((double)A.num / A.den) > ((double)B.num / B.den);
}

template <typename T>
void
arr_accending_order(array_fixed<T> &arr)
{
    int size = arr.num_elements;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compare_fraction(arr[i], arr[j])) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int
main()
{
    array_fixed<fraction_t> arrA{{1, 2}, {2, 3}};
    arr_accending_order(arrA);
    for (auto i : arrA) {
        std::cout << i.num << "/" << i.den << "\n";
    }
    return 0;
}