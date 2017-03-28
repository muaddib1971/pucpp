// The C++11 Standard recommends the use of the #pragma once declaration,
// rather than a #ifndef/define pair
#pragma once

// The PI from math.h gives better accuracy, but as this is in the lecture
// notes, it is included here
#define PI 3.14159265

// Our MAX macro that we are using in the src file, this is a simple
// conditional statement that works the same as in C
#define MAX(x, y) (x > y ? x : y)

