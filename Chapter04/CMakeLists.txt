set(SOURCES Program.cpp Test.cpp)
set(HEADERS Program.h ErrorHandler.h ExpressionParser.h Skipper.h IdentifierParser.h DeclerationParser.h AbstractSyntaxTree.h Annotation.h
    StringParser.h)

add_executable(Chapter04 ${HEADERS} ${SOURCES})

target_compile_definitions(Chapter04 PRIVATE CATCH_CPP14_OR_GREATER $<$<CONFIG:Debug>:BOOST_SPIRIT_DEBUG>)

target_link_libraries(Chapter04 
    PRIVATE 
        Boost::boost 
        Boost::system
        Boost::filesystem 
        Catch::Catch 
        includeHeaders)

parse_unit_tests(Chapter04)