#include <ntest/ntest.hpp>

int main ( void )
{

    ntest::assert_true([]()
    {
        return 1;
    });

    ntest::assert_true([]()
    {
        int a = 1;
        int b = 12;
        return
        (
            b > a
        );
    });

    ntest::assert_true([]()
    {
        //  Test with commas

        int array[] = { 1 , 2 , 3 };

        return
        (
            array[2] == 3
        );
    });

    ASSERT_TRUE
    (
        int a = 1;
        int b = 12;
        return
        (
            b > a
        );
    );

    ntest::assert_false([]()
    {
        return 0;
    });

    ntest::assert_false([]()
    {
        int a = 1;
        int b = 12;
        return
        (
            b <= a
        );
    });

    ASSERT_FALSE
    (
        int a = 1;
        int b = 12;
        return
        (
            b <= a
        );
    );

    ntest::assert_throw<int>([]()
    {
        throw 1;
    });

    ASSERT_THROW
    (
        int,
        {
            throw 1;
        }
    );

    ntest::assert_nothrow([]()
    {

    });

    ASSERT_NOTHROW
    (

    );

    return ntest::run() ? 0 : 1;

}
