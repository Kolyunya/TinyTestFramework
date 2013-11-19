//  NanoTest (ntest) - C++ unit-testing framework
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

#include "./../include/ntest/ntest.hpp"

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