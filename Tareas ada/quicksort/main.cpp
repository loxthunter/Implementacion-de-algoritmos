#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <cstdlib>
#include <ctime>
const int tamano = 10, MAXIMO = 10000;
void quicksort( int * const, int, int );
void swap( int * const, int * const );
int main()
{
  int arregloAordenar[ tamano ] = { 0 };
  int loop;
  srand( time( 0 ) );
  for ( loop = 0; loop < tamano; ++loop )
    arregloAordenar[ loop ] = rand() % MAXIMO;
  cout << "Los valores del arreglo antes de ordenarse son:\n";
  for ( loop = 0; loop < tamano; ++loop )
    cout << setw( 4 ) << arregloAordenar[ loop ];
  cout << "\n\n";
  if ( tamano == 1 )
    cout << "El arreglo esta ordenado: " << arregloAordenar[ 0 ] << '\n';
  else {
    quicksort( arregloAordenar, 0, tamano - 1 );
    cout << "Los valores del arreglo ordenado son:\n";
    for ( loop = 0; loop < tamano; ++loop )
      cout << setw( 4 ) << arregloAordenar[ loop ];
    cout << endl;
  }
  return 0;
}
void quicksort( int * const arreglo, int first, int last )
{
  int particion( int * const, int, int );
  int posicionActual;
  if ( first >= last )
    return;
  posicionActual = particion( arreglo, first, last );
  quicksort( arreglo, first, posicionActual - 1 );
  quicksort( arreglo, posicionActual + 1, last );
}
int particion( int * const arreglo, int izquierda, int derecha )
{
  int posicion = izquierda;
  while ( true ) {
    while ( arreglo[ posicion ] <= arreglo[ derecha ] && posicion != derecha )
      --derecha;
    if ( posicion == derecha )
      return posicion;
    if ( arreglo[ posicion ] > arreglo[ derecha ]) {
      swap( &arreglo[ posicion ], &arreglo[ derecha ] );
      posicion = derecha;
    }
    while ( arreglo[ izquierda ] <= arreglo[ posicion ] && izquierda != posicion )
      ++izquierda;
    if ( posicion == izquierda )
      return posicion;
    if ( arreglo[ izquierda ] > arreglo[ posicion ] ) {
      swap( &arreglo[ posicion ], &arreglo[ izquierda ] );
      posicion = izquierda;
    }
  }
}
void swap( int * const ptr1, int * const ptr2 )
{
  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}
