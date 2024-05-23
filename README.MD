Group Members:

Moksha, Misha, Nidhi

To compile the program you can use the make file. Open a terminal and run –
make

This generates an executable flame.cp . the bash script can be used as ./flame_cp “$@”

To compile and execute manually: gcc my_copy.c -o flame_cp. 
Run the program with the specific arguments - ./flame_cp -i source_file -o destination_file

Example - flame_cp -i input.txt -o output.txt

O_WRONLY: Open for write-only access.
O_CREAT: Create the file if it does not exist.
O_TRUNC: Truncate the file if it exists and is opened for writing.
O_EXCL: Error if open is called to create but file already exists
File permission flags: S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH.
Exit Error Codes
The program provides the following exit error codes:

0: Copy successful.
2: Invalid flags when compared to the usage examples.
3: Could not locate input file.
4: Error in creating or writing output file. File already exists
Other: Unknown error.

--------------------------------------
make
./flame_cp -i text.txt -o out.txt

(Error descripytion does not appear from bash but file is created)
./bash.sh $?
(Wrong exit code is being returned)

----------------------------------------------------
with the following commands, the correct exit code is being returned: 
make
/bash.sh -i text.txt -o out.txt
(Copy is successfully created with the correct description) 




