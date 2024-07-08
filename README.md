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
time ./bin/pi-threads
````

## Questões

1. As threads implementadas são preemptivas ou cooperativas? Explique sua resposta.
   
   >As threads criadas com a biblioteca pthreads (POSIX threads) em C são preemptivas. Isso significa que o escalonador do sistema operacional pode interromper a execução de uma thread em qualquer momento para dar lugar à execução de outra thread, com base em critérios de prioridade e tempo de execução, entre outros fatores.
   >O comportamento preemptivo permite que o sistema operacional distribua de maneira mais equitativa os recursos da CPU entre as várias threads, aumentando a responsividade e a eficiência do sistema, especialmente em sistemas multitarefa.

3. Que modelo de threads o sistema operacional que você usou implementa (N:1, 1:1 ou N:M)? Como isso pode ser deduzido a partir dos experimentos?
   > O Modelo de Threads utilizada no sistema operacional que utilizamos (O Unix Ubuntu 22.04), é conhecido como NPTL (Native POSIX Thread library). O NPTL é uma biblioteca de Threads 1:1, onde nesse modelo, cada thread de usuário possui uma       thread correspondente no núcleo
   
   >Criação e Observação de Threads:
    Crie um programa em C ou Python que crie várias threads.
    Use a ferramenta top ou htop para observar a criação de threads no sistema. Com o modelo 1:1, você verá que para cada thread de usuário criada, uma nova thread aparece listada no top ou htop.
