This is a Linux virus which looks for executable files in the directory it is present and then infects it.

Execution:

wrapper.c contains the C code that calls the shell script file(wrapper.to_call) that de-xors the virus file wrapper.virus and then runs it.
wrapper.virus_dexored is the deXORed virus shell script file.
The original file wrapper.x21 is then executed at the end.

wrapper.xorcipher is the compiled executable file of xorcipher.c that does the XOR of the virus file with the original filename as the "key".

wrapper is the compiled executable of wrapper.c.

Just run wrapper file using ./wrapper and the it infects the executable files if any in the current directory if it is not already infected.
