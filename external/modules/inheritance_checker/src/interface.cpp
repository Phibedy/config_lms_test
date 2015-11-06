#include "inheritance_checker.h"

extern "C" {
void* getInstance () {
    return new InheritanceChecker();
}
}
