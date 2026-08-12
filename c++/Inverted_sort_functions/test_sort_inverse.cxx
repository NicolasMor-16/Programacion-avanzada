#include <iostream>
#include <cstdlib>
#include <chrono>
#include "sort_functions.h"

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  // Get command line arguments
 if( argc < 3 )
  {
    std::cerr
      << "Usage: " << argv[ 0 ]
      << " count"
      << " buscado "
      << std::endl;
    return( -1 );

  } // fi

  long count = std::atol( argv[ 1 ] );
  long buscado = std::atol( argv[ 2 ] );

  // Get some memory
  long* a_bubble = new long[ count ];
  long* a_quick = new long[ count ];
  long* a_heap = new long[ count ];

  // Fill arrays
  for( long c = 0; c < count; ++c )
  {
    a_bubble[ c ] = count - c;
    a_quick[ c ] = count - c;
    a_heap[ c ] = count - c;

  } // rof

  // Bubble sort
  auto start_bubble = std::chrono::high_resolution_clock::now();
  bubblesort( a_bubble, count );
  auto end_bubble = std::chrono::high_resolution_clock::now();
  auto time_bubble = std::chrono::duration_cast<std::chrono::nanoseconds>(end_bubble - start_bubble);

  // Quick sort
  auto start_quick = std::chrono::high_resolution_clock::now();
  quicksort( a_quick, count );
  auto end_quick = std::chrono::high_resolution_clock::now();
  auto time_quick = std::chrono::duration_cast<std::chrono::nanoseconds>(end_quick - start_quick);

  // Heap sort
  auto start_heap = std::chrono::high_resolution_clock::now();
  heapsort( a_heap, count );
  auto end_heap = std::chrono::high_resolution_clock::now();
  auto time_heap = std::chrono::duration_cast<std::chrono::nanoseconds>(end_heap - start_heap);

  // Show results
  std::cout
    << "Ordenamiento tamanio "
    << count
    << " "
    << is_sorted( a_bubble, a_bubble + count ) << " "
    << is_sorted( a_quick, a_quick + count ) << " "
    << is_sorted( a_heap, a_heap + count ) << " time bubble "
    << static_cast<double>(time_bubble.count()) << " time quick "
    << static_cast<double>(time_quick.count()) << " time heap "
    << static_cast<double>(time_heap.count()) << std::endl;

    // searching found

    auto start_linear = std::chrono::high_resolution_clock::now();
    long indLinear = linearSearch(a_heap,count,buscado);
    auto end_linear = std::chrono::high_resolution_clock::now();
    auto time_linear = std::chrono::duration_cast<std::chrono::nanoseconds>(end_linear - start_linear);
    std::cout<< static_cast<double>(time_linear.count())<<" time busqueda lineal"<<std::endl;

    auto start_binary = std::chrono::high_resolution_clock::now();
    long indBinary = binarySearch(a_heap,count,buscado);
    auto end_binary = std::chrono::high_resolution_clock::now();
    auto time_binary = std::chrono::duration_cast<std::chrono::nanoseconds>(end_binary - start_binary);
    std::cout<< static_cast<double>(time_binary.count())<<" time busqueda binaria"<<std::endl;

    buscado = -10;
    start_linear = std::chrono::high_resolution_clock::now();
    indLinear = linearSearch(a_heap,count,buscado);
    end_linear = std::chrono::high_resolution_clock::now();
    time_linear = std::chrono::duration_cast<std::chrono::nanoseconds>(end_linear - start_linear);
    std::cout<< static_cast<double>(time_linear.count())<<" time busqueda lineal"<<std::endl;

    start_binary = std::chrono::high_resolution_clock::now();
    indBinary = binarySearch(a_heap,count,buscado);
    end_binary = std::chrono::high_resolution_clock::now();
    time_binary = std::chrono::duration_cast<std::chrono::nanoseconds>(end_binary - start_binary);
    std::cout<< static_cast<double>(time_binary.count())<<" time busqueda binaria"<<std::endl;

   // Free memory
   delete[] a_bubble;
   delete[] a_quick;
   delete[] a_heap;

   return( 0 );
}