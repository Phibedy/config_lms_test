#include "inheritance_checker1.h"

extern "C" {
void* getInstance () {
    return new InheritanceChecker1();
}
}
