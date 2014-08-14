#ifndef _NTEST_HPP_
#define _NTEST_HPP_

#include <functional>
#include <vector>
#include <iostream>

namespace NTEST
{

    //  Function taking no arguments and returning "bool"
    typedef std::function<bool(void)> bool_function;

    //  Function taking no arguments and returning nothing
    typedef std::function<void(void)> void_function;

    //  A collection of "bool_function" objects
    typedef std::vector<bool_function> bool_functions;

    class TEST
    {

        public:

            //  Tests the `test_function` function to return `true`
            static void TRUE ( bool_function test_function );

            //  Tests the `test_function` function to return `false`
            static void FALSE ( bool_function test_function );

            //  Tests the `test_function` function to thow `exception` exception
            template <typename exception>
            static void THROW ( void_function test_function );

            //  Tests the `test_function` function not to thow any exceptions
            static void NOTHROW ( void_function test_function );

            //  Runs all tests
            static bool RUN ( void );

        private:

            //  Collection of tests
            static bool_functions test_functions;

    };

}

//  Macro for NTEST::TEST::TRUE
#define TEST_TRUE(test) NTEST::TEST::TRUE([](){test})

//  Macro for NTEST::TEST::FALSE
#define TEST_FALSE(test) NTEST::TEST::FALSE([](){test})

//  Macro for NTEST::TEST::TROW<Exception>
#define TEST_THROW(exception,test) NTEST::TEST::THROW<exception>([](){test})

//  Macro for NTEST::TEST::NOTHROW
#define TEST_NOTHROW(test) NTEST::TEST::NOTHROW([](){test})

//  Macro for NTEST::TEST::RUN
#define TEST_RUN() NTEST::TEST::RUN()

//  Include template methods implementation
#include "ntest.tpp"

//  include non-template methods implementation
#include "ntest.ipp"

#endif