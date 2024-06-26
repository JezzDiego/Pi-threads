## Calculating the value of Pi through threads in C

The objective of this project is to better understand the concept of threads and how they can be used to better utilize the processing resources available in modern computers. To do this, a C program will be built using the Posix Threads library to calculate Pi using N simultaneous threads. The value of Pi can be approximated by the Leibniz-Grégory series:

### How to create the executable file

<hr />

The command below utilizes the GNU Compiler Collection to create a Unix executable file. It links the `math` and `pthread` unix libraries, which were used to build the code. Please do not commit binary generated files created by this command


````shell
gcc -o bin/pi-threads pi-threads.c -pthread -lm
````

<br />

Then, run the generated file looking for the execution time.

````shell
time ./pi
````
