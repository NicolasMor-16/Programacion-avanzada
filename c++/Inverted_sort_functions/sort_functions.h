#ifndef __SORT_FUNCTIONS__H__
#define __SORT_FUNCTIONS__H__

void bubblesort( long* a, long n );
void quicksort( long* a, long n );
void heapsort( long* a, long n );
long linearSearch(long *arr, long tam, long buscado);
long binarySearch(long *arr, long tam, long buscado);

template< class I >
bool is_sorted( I first, I last )
{
    if( first == last )
        return( true );
    I next = first;
    while( ++next != last )
    {
        if( *next < *first )
            return( false );
        ++first;

    } // elihw
    return( true );
}

#endif // __SORT_FUNCTIONS__H__