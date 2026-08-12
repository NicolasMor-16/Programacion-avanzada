#include <iostream>
#include <algorithm>
#include "sort_functions.h"

// -------------------------------------------------------------------------
void bubblesort( long* a, long n )
{
  for( unsigned long j = 0; j < n; ++j )
  {
    for( unsigned long i = 0; i < n - 1; ++i )
    {
      if( a[ i ] > a[ i + 1 ] )
      {
        long tmp = a[ i ];
        a[ i ] = a[ i + 1 ];
        a[ i + 1 ] = tmp;

      } // fi

    } // rof

  } // rof
}

// -------------------------------------------------------------------------
long quicksort_partition( long* a, long p, long r )
{
  long x = a[ r ];
  long j = p - 1;
  for( long i = p; i < r; i++ )
  {
    if( x >= a[ i ] )
    {
      j = j + 1;
      long temp = a[ j ];
      a[ j ] = a[ i ];
      a[ i ] = temp;

    } // fi

  } // rof
  a[ r ] = a[ j + 1 ];
  a[ j + 1 ] = x;

  return( j + 1 );
}

// -------------------------------------------------------------------------
void quicksort_dummy( long* a, long p, long r )
{
  if( p < r )
  {
    long q = quicksort_partition( a, p, r );
    quicksort_dummy( a, p, q - 1 );
    quicksort_dummy( a, q + 1, r );

  } // fi
}

// -------------------------------------------------------------------------
void quicksort( long* a, long n )
{
  quicksort_dummy( a, 0, n - 1 );
}

// -------------------------------------------------------------------------
void heapsort( long* a, long n )
{
  std::make_heap( a, a + n );
  std::sort_heap( a, a + n );
}

// -------------------------------------------------------------------------
long linearSearch(long *arr, long tam, long buscado)
{
    long cont = 0;
    for (long i = 0; i < tam; i++)
    {
        cont++;
        if (arr[i] == buscado)
        {
             std::cout << "Linear Search Encontrado " << cont << " accesos al arreglo " << std::endl;
             return i;
        }
     }
    std::cout << "Linear Search NO Encontrado " << cont << " Accesos al arreglo " << std::endl;
    return -1;
}

// -------------------------------------------------------------------------
long binarySearch(long *arr, long tam, long buscado)
{
    long cont = 0, low = 0, high = tam - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cont++;
        if (arr[mid] == buscado)
        {
            std::cout << " Binary Search Encontrado " << cont << " accesos al arreglo " << std::endl;
            return mid;
        }
        else if (arr[mid] > buscado)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    std::cout << " Binary Search NO Encontrado " << cont << " Accesos al arreglo" << std::endl;
    return -1;
}