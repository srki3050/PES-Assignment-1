# PES-Assignment-1
Code for Assignment 1 for PES, ECEN 5813, Spring 2022
There are 6 functions and 6 test functions required for this.

1. uint_to_binstr() - This converts the file from normal integer to binary string prefixed with "0b" and suffixed with a null character '\0'.
                       The border validation this does is it checks whether the destination buffer can hold the string.
                       The given number can be represented as a binary number consisting of atmost nbits.
                       The number should not be negative.
                       returns the length of the destination buffer excluding the null character at the end.
2. int_to_binstr() -  This converts the file from normal integer to binary string prefixed with "0b" and suffixed with a null character '\0'.
                       The border validation this does is it checks whether the destination buffer can hold the string.
                       The given number can be represented as a binary number consisting of atmost nbits.
                       Negative case should be addressed.
                       returns the length of the destination buffer excluding the null character at the end.
3. uint_to_hexstr() - This converts the file from normal integer to hex format prefixed with a "0x" and suffixed with a null character '\0'.
                      The border validation this does is it checks whether the destination buffer can hold the string.
                       The given number can be represented as a binary number consisting of atmost nbits.
                       The number should not be negative.
                       returns the length of the destination buffer
                       excluding the null character at the end.
                       nbits should only hold value 4,8,16 or 32.
4. twiggle_bit() - This performs logical operations depending upon the command fed by the enum object.
                   Error is returned if the number is out of range or any other command is fed other than what is there in the enumeration.
                   The resulting output is returned.
5. Grab_three_bit() - This brings the bit number specified, bit + 1 and bit +2th bit as the LSB and prints that.
                       Since the input is a 32bit number, the bit value suppose to perform this activity should be a positive number less than 30.
                       The number coming out of the last 3 digits is returned as output.
6. Hex Dump() - This code provided the hex of all the input characters and dumps it. The line is broken at line 16 and then the next offset position is printed.
                checks if the destination buffer size is atleast the size of the input string.
