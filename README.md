*This project has been created as part of the 42 curriculum by sloubiat*

# Printf

# Description

The printf project aims to recreate the standard C function printf. The goal is to display formatted output to the standard output based on a given format string.

This project involves parsing a format string and handling different format specifiers to print various types of data, such as characters, strings, and integers. It helps improve understanding of C programming concepts, including variadic functions and output formatting.

# Resources
References and Tools

I Use the C Standard Library and the man printf manual were used to understand and test the behavior of the original printf function. The Francinette tester was also used to verify the correctness of the implementation and ensure that the output matched the expected results.

Artificial Intelligence was used only to help write and improve the README documentation. AI was not used to generate or implement the project code.

# instructions

To compile the library, run the `make` command in the project directory. This will generate the `libftprintf.a` static library.

Once compiled, the library can be added to another project by including the header file and linking the libftprintf.a file during compilation. After that, the ft_printf function can be used like the standard printf function.

# Additional
## Algorithm and Data Structures

The ft_printf function works by parsing the format string character by character. Regular characters are printed directly, while format specifiers introduced by % are detected and handled accordingly.

Variadic arguments are accessed using va_list, and each supported format specifier is processed by a dedicated function. The function keeps track of the number of printed characters and returns this value.

The main data structure used is va_list from the C Standard Library. This approach was chosen for its simplicity, low memory usage, and clear separation of responsibilities.