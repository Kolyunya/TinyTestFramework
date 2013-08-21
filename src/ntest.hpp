//	Nano-Test (ntest) - C++ unit-testing framework
//	Copyright (C) 2013 Oleynikov Nikolay
//	
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//	
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//	
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.
//	
//	Author email: OleynikovNY@mail.ru

#ifndef _NTEST_HPP_
#define _NTEST_HPP_

#include <functional>	//	std::function
#include <vector>		//	std::vector
#include <iostream>		//	std::cout

namespace NTEST
{
	
	//	Function taking no arguments and returning "bool"
	typedef std::function<bool(void)>		bool_function;

	//	Function taking no arguments and returning nothing
	typedef std::function<void(void)>		void_function;
	
	//	A collection of "bool_function" objects
	typedef std::vector<bool_function>		bool_functions;

	class TEST
	{
		
		public:

			//	Tests the `test_function` function to return `true`
			static void							TRUE ( bool_function test_function );
			
			//	Tests the `test_function` function to return `false`
			static void							FALSE ( bool_function test_function );
		
			//	Tests the `test_function` function to thow `exception` exception
			template <typename exception>
			static void							THROW ( void_function test_function );
		
			//	Tests the `test_function` function not to thow any exceptions
			static void							NOTHROW ( void_function test_function );
		
			//	Runs all tests
			static bool							RUN ( void );
			
		private:
		
			//	Collection of tests
			static bool_functions				test_functions;

	};
	
}

//	Convenient macro for NTEST::TEST::TRUE
#define TEST_TRUE(test) NTEST::TEST::TRUE([](){test})

//	Convenient macro for NTEST::TEST::FALSE
#define TEST_FALSE(test) NTEST::TEST::FALSE([](){test})

//	Convenient macro for NTEST::TEST::TROW<Exception>
#define TEST_THROW(exception,test) NTEST::TEST::THROW<exception>([](){test})

//	Convenient macro for NTEST::TEST::NOTHROW
#define TEST_NOTHROW(test) NTEST::TEST::NOTHROW([](){test})

//	Convenient macro for NTEST::TEST::RUN
#define TEST_RUN() NTEST::TEST::RUN()

//	Include template methods implementation
#include "ntest.tpp"

//	include non-template methods implementation
#include "ntest.ipp"

#endif	// _NTEST_HPP_