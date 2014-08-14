#ifndef _NASSERT_HPP_
#define _NASSERT_HPP_

#include <functional>
#include <vector>
#include <iostream>

namespace ntest
{

    //  A function taking no arguments and returning "bool"
    typedef std::function<bool(void)> bool_function;

    //  A function taking no arguments and returning nothing
    typedef std::function<void(void)> void_function;

    //  A collection of "bool_function" objects
    typedef std::vector<bool_function> bool_functions;

    //  Tests the `test_function` to return `true`
    void assert_true ( bool_function test_function );

    //  Tests the `test_function` to return `false`
    void assert_false ( bool_function test_function );

    //  Tests the `test_function` to thow `exception` exception
    template <typename exception>
    void assert_throw ( void_function test_function );

    //  Tests the `test_function` not to thow any exceptions
    void assert_nothrow ( void_function test_function );

    //  Runs all tests
    bool run ( void );

    //  Collection of tests
    static bool_functions test_functions = {};

}

//  A macro for ntest::assert_true
#define ASSERT_TRUE(test) ntest::assert_true([](){test})

//  A macro for ntest::assert_false
#define ASSERT_FALSE(test) ntest::assert_false([](){test})

//  A macro for ntest::assert_throw
#define ASSERT_THROW(exception,test) ntest::assert_throw<exception>([](){test})

//  A macro for ntest::assert_nothrow
#define ASSERT_NOTHROW(test) ntest::assert_nothrow([](){test})

//  A macro for ntest::run
#define RUN() ntest::run()

//  Include template methods implementation
#include "ntest.tpp"

//  Include non-template methods implementation
#include "ntest.ipp"

#endif