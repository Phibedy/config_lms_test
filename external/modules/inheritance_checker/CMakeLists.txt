set(SOURCES
    "src/inheritance_checker.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/inheritance_checker.h"
)

include_directories(include)
add_library(inheritance_checker MODULE ${SOURCES} ${HEADERS})
target_link_libraries(inheritance_checker PRIVATE lmscore)
