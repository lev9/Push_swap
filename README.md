# Push_swap

A Hive Helsinki school algorithm project Push_swap:

A set of int values, 2 stacks and a set of
instructions to manipulate both stacks.
Goal is to arrange the values in stack a with the help of stack b and a set of moves(*:



a simple test:
	./push_swap "2 1 3" 


create a set of random numbers from min to max (negatives :

	ARG=$(printf '%s ' `seq [min] [max] | sort -R`);

push_swap comes up with a set of instructions to arrange them:

        ./push_swap $ARG

checker will return OK if push_swap's instructions worked:
	
	./push_swap $ARG | ./checker $ARG

check how many moves it takes to arrange the numbers:

	./push_swap $ARG | ./checker $ARG -z

a little visual:

	./push_swap $ARG | ./checker $ARG -g

a push_swap tester:

go to tester

	./push_swap_test.sh [amount of test rounds]
	./push_swap_test.sh [amount of test rounds] time  to check speed
	./push_swap_test.sh [amount of test rounds] norm  to check norm
	./push_swap_test.sh [amount of test rounds] time norm  to check speed and norm

<img align="left" width="310" height="270" SRC="pics/w3d1.png">
