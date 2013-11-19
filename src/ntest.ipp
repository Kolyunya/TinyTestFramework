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

namespace NTEST
{

    bool_functions      TEST::test_functions = {};

    void                TEST::TRUE ( bool_function test_function )
    {

        TEST::test_functions.push_back(test_function);

    }

    void                TEST::FALSE ( bool_function test_function )
    {

        TEST::test_functions.push_back
        (
            [&test_function]()
            {
                return ! test_function();
            }
        );

    }

    void                TEST::NOTHROW ( void_function test_function )
    {

        TEST::TRUE([&test_function]()
        {

            try
            {

                //  Try to execute the test function
                test_function();

            }

            catch ( ... )
            {

                //  Exception was thrown
                return false;

            }

            //  No exception was thrown
            return true;

        });

    }

    bool                TEST::RUN ( void )
    {

        bool all_tests_succeeded = true;
        int test_id = 0;

        for ( auto test_functions_itr = test_functions.begin() ; test_functions_itr != TEST::test_functions.end() ; test_functions_itr++ , test_id++ )
        {

            if ( ! (*test_functions_itr)() )
            {

                std::cout << "Test #" << test_id << " failed" << std::endl;
                all_tests_succeeded = false;
                continue;

            }

            std::cout << "Test #" << test_id << " succeeded" << std::endl;

        }

        std::cout <<  ( all_tests_succeeded ? "All tests succeeded" : "Some tests failed" ) << std::endl;

        return all_tests_succeeded;

    }

}