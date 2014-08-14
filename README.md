# Tiny C++ unit-testing framework

## Description

A (very) tiny C++ unit-testing header-only framework.

## Installation

Just include the `include/ntest/ntest.hpp` to your source file and you are good to go.

## Usage

### Assertions of `true`

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

### Assertions of `false`

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

### Assertions of `throw`

~~~C++
//  A passing test
ntest::assert_throw<int>([]()
{
    throw 42;
});

//  A failing test
ntest::assert_throw([]()
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