# Tiny C++ unit-testing framework

## Description

A (very) tiny C++ unit-testing header-only framework.

## Installation

Just include the `include/ntest/ntest.hpp` to your source file and you are good to go.

## Usage

### Assertions of `true`

~~~C++
ntest::assert_true([]()
{
    return true;
});
~~~

### Assertions of `false`

~~~C++
ntest::assert_false([]()
{
    return false;
});
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