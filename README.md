# A tiny C++ unit-testing framework

## Description

A (very) tiny C++ unit-testing header-only framework.

## Installation

Just include the `include/ntest/ntest.hpp` to your source file and you are good to go.

## Usage

### Assertion of `true`

~~~C++
//  A passing test
ntest::assert_true([]()
{
    return 42 == 42;
});

//  A failing test
ntest::assert_true([]()
{
    return 42 != 42;
});

//  A shorthand macro
ASSERT_TRUE
(
    return true;
)
~~~

### Assertion of `false`

~~~C++
//  A passing test
ntest::assert_false([]()
{
    return 42 != 42;
});

//  A failing test
ntest::assert_true([]()
{
    return 42 == 42;
});

//  A shorthand macro
ASSERT_FALSE
(
    return false;
)
~~~

### Assertion of `throw`

~~~C++
//  A passing test
ntest::assert_throw<int>([]()
{
    throw 42;
});

//  A failing test
ntest::assert_throw<int>([]()
{
    return "42";
});

//  A shorthand macro
ASSERT_THROW
(
    int,
    {
        throw 42;
    }
)
~~~

### Assertion of `nothrow`

~~~C++
//  A passing test
ntest::assert_nothrow([]()
{
    //  No exceptions are thrown here
});

//  A failing test
ntest::assert_nothrow([]()
{
    throw 42;
});

//  A shorthand macro
ASSERT_NOTHROW
(
    {
        //  No exceptions are thrown here
    }
)
~~~

### Running tests
~~~C++
#include <ntest/ntest.hpp>
int main ( void )
{
    /*
     * Some assertions
     */
    return ntest::run() ? 0 : 1;
}
~~~