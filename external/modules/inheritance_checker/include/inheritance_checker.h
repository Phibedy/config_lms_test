#ifndef INHERITANCE_CHECKER_H
#define INHERITANCE_CHECKER_H

#include <lms/datamanager.h>
#include <lms/module.h>

class InheritanceChecker : public lms::Module {
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
};

#endif // INHERITANCE_CHECKER_H
