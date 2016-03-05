#include <iostream>

int main() {
  int* p1;
  int* p2;
  int x = 5;
  int y = 15;

  p1 = &x; 	 	// x contains _5___; y _15___; p1 _address of x___; p2 __//__
 
  p2 = &y;	 	// x contains __5__; y _15___; p1 __address of x__; p2 _address of y___
 
  *p1 = 6; 		// x contains __6__; y __15__; p1 _address of x___; p2 _address of y___
 
  *p1 = *p2;	// x ____; y ____; p1 ____; p2 ____
 
  p2 = p1; 		// x ____; y ____; p1 ____; p2 ____
 
  *p1 = *p2+10; // x ____; y ____; p1 ____; p2 ____
  
  return 0;
}
