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