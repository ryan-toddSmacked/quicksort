#include "quicksort.h"

#define M (9)
#define NSTACK (127)
static int istack[NSTACK];  /* Auxillary storage */
#define SWAP(a, b) t = arr[a]; arr[a] = arr[b]; arr[b] = t;

void quicksort (int * restrict arr, int nElems) {
    int pivotIndex, diff, L, R, i, j, jstack = 0, pivot, t;
    if (nElems < 2) return;

    istack[jstack++] = 0;
    istack[jstack++] = nElems - 1;

    for (;;) {
        R = istack[--jstack];
        L = istack[--jstack];
        diff = R - L;
        /* insertion sort if subset array small enough */
        if (diff < M) {
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
            SWAP(L, L + (R - L) / 2);
            pivot = arr[L];
            pivotIndex = L;
            for (i = R; i > pivotIndex; i--) {
                if (arr[i] < pivot) {
                    pivotIndex++;
                    while (arr[pivotIndex] <= pivot && pivotIndex < i)
                        pivotIndex++;
                    SWAP(pivotIndex, i);
                }
            }
            SWAP(L, pivotIndex);
            istack[jstack++] = L;
            istack[jstack++] = pivotIndex - 1;
            istack[jstack++] = pivotIndex + 1;
            istack[jstack++] = R;
        }
    }
}

