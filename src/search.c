#include "search.h"

/*
 * Binary Searching algorithm using the iterative method.
 * first parameter (*arr): Pointer to the array to be searched.
 * Second parameter (l): Left bound of search.
 * Third parameter (r): Right bound of search.
 * Fourth parameter (x): value to be searched for.
 */
int binarysearch(const int *arr, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

    while (arr[mid] != x)
    {
        if (r <= l || r < 0)
            return -1;

        if (arr[mid] > x)
            // If element is smaller than the pivot (middle) element.
            r = mid - 1;
        else
            // Element is on the right of the pivot element
            l = mid + 1;

        mid = l + (r - l) / 2;
    }

    // If the element is not in the array
    return mid;
}
