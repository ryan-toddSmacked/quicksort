#ifndef __QUICKSORT_C_DECL_H
#define __QUICKSORT_C_DECL_H

#include <stdint.h>

/******************************************************************************
 * Macro -- Quicksort_Create
 *
 * Defines the following functions:
 *  Swap(type * data, int_fast32_t a, int_fast32_t b);
 *    // Swaps two elements in array.
 * 
 *  Partition(type * data, int_fast32_t leftBound, int_fast32_t rightBound);
 *    // Partitions data, placing all lower values to left and upper values to right.
 *    // Pivot value is the midpoint of leftBound and rightBound.
 *
 *  Recursive(type * data, int_fast32_t leftBound, int_fast32_t rightBound);
 *    // Recursive definition of sorting calls.
 *
 *  name(type * data, int_fast32_t nElems);
 *    // Function to call to sort data.
 *
 *  Inputs:
 *      name: Name of the function that will sort elements.
 *      type: Primitive type that will sorted.
 *
 * Sorts the data inplace.
 *
 *****************************************************************************/

#ifdef __cplusplus
/* c++ version, it really just doesnt use the restrict keyword... */

#define Quicksort_Create(name, type)                                                        \
static inline void Swap_##name (type * data, int_fast32_t i, int_fast32_t j) {              \
    const type temp = data[i]; data[i] = data[j]; data[j] = temp;                           \
}                                                                                           \
static int_fast32_t Partition_##name (type * data, int_fast32_t first, int_fast32_t last) { \
    type pivot;                                                                             \
    int_fast32_t index, sindex;                                                             \
    Swap_##name (data, first, first + (last - first) / 2);                                  \
    pivot = data[first];                                                                    \
    sindex = first;                                                                         \
    for (index = first + 1; index <= last; index++) {                                       \
        if (data[index] < pivot) {                                                          \
            sindex++;                                                                       \
            Swap_##name (data, sindex, index);                                              \
        }                                                                                   \
    }                                                                                       \
    Swap_##name (data, first, sindex);                                                      \
    return sindex;                                                                          \
}                                                                                           \
static void Recursive_##name (type * data, int_fast32_t first, int_fast32_t last) {         \
    int_fast32_t pivotLoc = Partition_##name (data, first, last);                           \
    if ((pivotLoc - 1) > first)                                                             \
        Recursive_##name (data, first, pivotLoc - 1);                                       \
    if ((pivotLoc + 1) < last)                                                              \
        Recursive_##name (data, pivotLoc + 1, last);                                        \
}                                                                                           \
void name (type * data, int_fast32_t nElems) {                                              \
    if (nElems < 2) return;                                                                 \
    Recursive_##name (data, 0, nElems - 1);                                                 \
}

#else
/* C version, uses the restrict keyword. Im not well versed on if this keyword is important
    or adds any positive value to the sorting functions */

#define Quicksort_Create(name, type)                                                                    \
static inline void Swap_##name (type * restrict data, int_fast32_t i, int_fast32_t j) {                 \
    const type temp = data[i]; data[i] = data[j]; data[j] = temp;                                       \
}                                                                                                       \
static int_fast32_t Partition_##name (type * restrict data, int_fast32_t first, int_fast32_t last) {    \
    type pivot;                                                                                         \
    int_fast32_t index, sindex;                                                                         \
    Swap_##name (data, first, first + (last - first) / 2);                                              \
    pivot = data[first];                                                                                \
    sindex = first;                                                                                     \
    for (index = first + 1; index <= last; index++) {                                                   \
        if (data[index] < pivot) {                                                                      \
            sindex++;                                                                                   \
            Swap_##name (data, sindex, index);                                                          \
        }                                                                                               \
    }                                                                                                   \
    Swap_##name (data, first, sindex);                                                                  \
    return sindex;                                                                                      \
}                                                                                                       \
static void Recursive_##name (type * restrict data, int_fast32_t first, int_fast32_t last) {            \
    int_fast32_t pivotLoc = Partition_##name (data, first, last);                                       \
    if ((pivotLoc - 1) > first)                                                                         \
        Recursive_##name (data, first, pivotLoc - 1);                                                   \
    if ((pivotLoc + 1) < last)                                                                          \
        Recursive_##name (data, pivotLoc + 1, last);                                                    \
}                                                                                                       \
void name (type * restrict data, int_fast32_t nElems) {                                                 \
    if (nElems < 2) return;                                                                             \
    Recursive_##name (data, 0, nElems - 1);                                                             \
}

#endif




#endif
