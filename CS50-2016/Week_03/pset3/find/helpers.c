/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

void insertionSort(int values[], int n)
{
    int min, temp;
    for (int x = 0; x < n-1; x++)
    {
        min = x;
        for (int y = x; y < n; y++)
        {
            if(values[min] > values[y] && values[y] != 99999) min = y;
        }
        temp = values[x];
        values[x] = values[min];
        values[min] = temp;
    }
    
    return;
}

bool linearSearch(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 1) return false;
    for (int x = 0; x < n; x++) if (value == values[x]) return true;
    return false;
}

bool binarySearch(int value, int values[], int n)
{
    int *aux = malloc(sizeof(int)*n);
    
    if (value == values[0] || value == values[n-1] || value == values[(n/2)]) 
    {
        return true;
    }
    else if (value < values[(n/2)]) 
    {
        for (int x = 0; x < n/2;x++) 
        {
            aux[x] = values[x];
        }
    }
    else if (value > values[(n/2)]) 
    {
        int y = 0;
        for (int x = (n/2) + 1; x < n;x++) 
        {
            aux[y] = values[x];
            y++;
        }
    }
    return (n/2 == 0 ? false : binarySearch(value, aux, n/2));
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    //return linearSearch(value, values, n);
    return binarySearch(value, values, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    insertionSort(values, n);
    return;
}

