#ifndef INHERITANCE_CHECKER1_H
#define INHERITANCE_CHECKER1_H

#include <lms/datamanager.h>
#include <lms/module.h>

class InheritanceChecker1 : public lms::Module {
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
};

#endif // INHERITANCE_CHECKER1_H
