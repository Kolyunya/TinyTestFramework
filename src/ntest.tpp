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

    template <typename exception>
    void    TEST::THROW ( void_function test_function )
    {

        TEST::TRUE([&test_function]()
        {

            try
            {

                //  Try to execute the test function
                test_function();

            }
            catch ( exception )
            {

                //  Exception was thrown and it's of the expected type
                return true;

            }
            catch ( ... )
            {

                //  Exception was thrown and it's of the unexpected type
                return false;

            }

            //  No exception was thrown
            return false;

        });

    }

}