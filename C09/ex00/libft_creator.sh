#!/bin/bash
gcc -c -Wall -Wextra -Werror f*.c && ar -rc libft.a f*.o
