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