
#ifndef M_ADD_H
#define M_ADD_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 6;
typedef int MEDUSOID_NUMBER[MAX_SIZE];

// This function adds two six-digit Medusoid numbers in a specified base.

// Details:
//
// input:  Two arrays of size 6 of type integer where each represents a 
//         six-digit Medusoid number
//         an integer that represents the age of the Medusoid.
//         a boolean indicating whether or not debugging information should
//         be output. (** see below)
//
// output: an array of size 6 of type integer which is the result of adding
//         the two input Medusoid numbers
//
// Addition is performed in the normal fashion whereby digit pairs starting
// from the right side are added to get the corresponding result digit. Digits
// exceeding the maximum or minimum digit will result in a carry. The addition
// of subsequent digit pairs will include the previous carry.
// 
// Assumptions and Limitations:
//
// It is assume that the Medusoid age is a value between 1 and 13.
// It is assume that the digits in a Medusoid number are valid, i.e. they fall
// into the correct range for the given base.
//
// Arrays whose size is not 6 will not be processed correctly:
//  - smaller arrays will have non-existent array elements processed,
//       i.e. between the array's maximum element and element 5
//  - larger arrays will have all elements larger than 5 not processed

// It is guaranteed that the addition will not generate a carry out from the
// high order digit. If a carry out were to occur it will be lost and an invalid
// result generated.
//
// **
// The debug flag has been included simply to provide detailed information
// about the addition of individual digit pairs. It has nothing to do with
// the addition and it TO BEE IGNORED during testing.

void add(int age, bool debug,
         const MEDUSOID_NUMBER num1,
         const MEDUSOID_NUMBER num2,
         MEDUSOID_NUMBER result);

#endif
