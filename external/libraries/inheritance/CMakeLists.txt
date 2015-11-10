set(SOURCES
 src/void.cpp
)

set(HEADERS
# include/inheritance/file.h
include/inheritance/inheritance.h
)

include_directories(include)
add_library(inheritance SHARED ${SOURCES} ${HEADERS})
target_link_libraries(inheritance PRIVATE lmscore)
