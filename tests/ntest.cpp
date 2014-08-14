#include <ntest/ntest.hpp>

int main ( void )
{

    NTEST::TEST::TRUE([]()
    {
        return 1;
    });

    NTEST::TEST::TRUE([]()
    {
        int a = 1;
        int b = 12;
        return
        (
            b > a
        );
    });

    NTEST::TEST::TRUE([]()
    {
        //  Test with commas

        int array[] = { 1 , 2 , 3 };

        return
        (
            array[2] == 3
        );
    });

    TEST_TRUE
    (
        int a = 1;
        int b = 12;
        return
        (
            b > a
        );
    );

    NTEST::TEST::FALSE([]()
    {
        return 0;
    });

    NTEST::TEST::FALSE([]()
    {
        int a = 1;
        int b = 12;
        return
        (
            b <= a
        );
    });

    TEST_FALSE
    (
        int a = 1;
        int b = 12;
        return
        (
            b <= a
        );
    );

    NTEST::TEST::THROW<int>([]()
    {
        throw 1;
    });

    TEST_THROW
    (
        int,
        {
            throw 1;
        }
    );

    NTEST::TEST::NOTHROW([]()
    {

    });

    TEST_NOTHROW
    (

    );

    return NTEST::TEST::RUN() ? 0 : 1;

}
