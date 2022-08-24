#include "quicksort.h"


// Macros
#define INSERTION_SORT_SIZE (9)
#define NSTACK (255)
#define SWAP(ptr, placeholder, index0, index1) do { \
    const int _INDEX0 = (index0);    \
    const int _INDEX1 = (index1);    \
    (placeholder) = (ptr)[_INDEX0];  \
    (ptr)[_INDEX0] = (ptr)[_INDEX1]; \
    (ptr)[_INDEX1] = (placeholder);  \
} while (0)

// Auxillary storage
static int istack[NSTACK] = { 0 };


int* quicksort (int* arr, int nElems) {
    // Keep as integers
    int pivotIndex, diff, L, R, i, j, jstack = 0;

    // These should be the array type being sorted
    int pivot, t;


    if (nElems < 2) return; 

    istack[jstack++] = 0;
    istack[jstack++] = nElems - 1;

    while (1) {
        R = istack[--jstack];
        L = istack[--jstack];
        diff = R - L;
        // insertion sort if subset array small enough
        if (diff < INSERTION_SORT_SIZE) {
            for (i = L + 1; i <= R; i++) {
                t = arr[i];
                j = i - 1;
                while (j >= L && arr[j] > t) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = t;
            }
            if (jstack == 0) break;
        }
        else {
            SWAP(arr, t, L, L + (R - L) / 2);
            pivot = arr[L];
            pivotIndex = L;
            for (i = R; i > pivotIndex; i--) {
                if (arr[i] < pivot) {
                    pivotIndex++;
                    while (arr[pivotIndex] <= pivot && pivotIndex < i)
                        pivotIndex++;
                    SWAP(arr, t, pivotIndex, i);
                }
            }
            SWAP(arr, t, L, pivotIndex);
            // To be extra safe, could add if statement to make sure
            //  jstack wont be larger than NSTACK.
            istack[jstack++] = L;
            istack[jstack++] = pivotIndex - 1;
            istack[jstack++] = pivotIndex + 1;
            istack[jstack++] = R;
        }
    }
    return arr;
}


