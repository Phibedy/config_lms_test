set(SOURCES
    "src/inheritance_checker1.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/inheritance_checker1.h"
)

include_directories(include)
add_library(inheritance_checker1 MODULE ${SOURCES} ${HEADERS})
target_link_libraries(inheritance_checker1 PRIVATE lmscore)
