#include "SparseMat.h"
#include <iostream>
using namespace std;

#define MAT_SIZE 100000
typedef SparseMat<float> SpMat;

// --------------- main ---------------
int main()
{
   SpMat mat(MAT_SIZE, MAT_SIZE, 0); // 100000 x 100000 filled with 0
   
   // test mutators
   mat.set(2, 5, 10);
   mat.set(2, 5, 35); // should overwrite the 10
   mat.set(3, 9, 21);
   mat.set(MAT_SIZE, 1, 5); // should fail silently
   mat.set(9, 9, mat.get(3, 9)); // should copy the 21 here
   mat.set(4,4, -9);
   mat.set(4,4, 0); // should remove the -9 node entirely
   mat.set(MAT_SIZE-1, MAT_SIZE-1, 99);
   // test accessors and exceptions
   try {
      cout << mat.get(7, 8) << endl;
      cout << mat.get(2, 5) << endl;
      cout << mat.get(9, 9) << endl;
      cout << mat.get(-4, 7) << endl; // should throw an exception
   } catch (...) {
      cout << "oops" << endl;
   }

   // show top left 15x15
   mat.showSubSquare(0, 15);
   // show bottom right 15x15
   mat.showSubSquare(MAT_SIZE - 15, 15);

   //added testers -----------------------------

   SpMat mat2(MAT_SIZE, MAT_SIZE, 1); // 100000 x 100000 filled with 1
   
   //set mutators
   mat2.set(2, 1, 21);
   mat2.set(2, 2, 5);
   mat2.set(2,3, -9);
   mat2.set(2,4, 0);

   //overloaded set mutators
   mat2 = 9; //should fail silently
   mat2.set(MAT_SIZE-2, MAT_SIZE-2) = 55;
   mat2.set(0,0) = 2;
   mat2.set(1,2);
   mat2 = 78;

   //show out of bounds below 0
   mat2.showSubSquare(-10, 5);  //forces -10 to be 0
   //show out of bounds above max size
   mat2.showSubSquare(MAT_SIZE - 8, 15); //won't show any values past max

   // show top left 6x6
   mat2.showSubSquare(0, 6);
   // show bottom right 6x6
   mat2.showSubSquare(MAT_SIZE - 6, 6);

   //test accessors
   try {
      cout << mat2.get(0,0) << endl;
      cout << mat2.get(1,1) << endl;
      cout << mat2.get(2,2) << endl;
      cout << mat2.get(MAT_SIZE, MAT_SIZE); //fail will exception
   } catch (...) {
      cout << "oops2" << endl;
   }

   //get rid of all data
   mat2.clear();

   //test accessors
   try {
      cout << mat2.get(0,0) << endl;
      cout << mat2.get(1,1) << endl;
      cout << mat2.get(2,2) << endl;
      cout << mat2.get(MAT_SIZE, MAT_SIZE);
   } catch (...) {
      cout << "oops2" << endl;
   }

   // show top left 6x6
   mat2.showSubSquare(0, 6);
   // show bottom right 6x6
   mat2.showSubSquare(MAT_SIZE - 6, 6);

   return 0;
}
