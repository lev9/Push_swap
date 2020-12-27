#!/bin/bash
G='\033[0;32m'
R='\033[0;31m'
O='\033[0;33m'
B='\033[0;34m'
Z='\033[48;5;037m'
Z2='\033[48;5;227m'
NO='\033[0m'
if (( $# < 1 )); then
echo -e "${G}
USAGE:
This test will test push_swap with 5, 100 and 500 numbers.
${NO}./push_swap_test.sh [amount of test rounds]
${NO}./push_swap_test.sh [amount of test rounds] time ${G} to check speed
${NO}./push_swap_test.sh [amount of test rounds] norm ${G} to check norm
${NO}./push_swap_test.sh [amount of test rounds] time norm" ${G} to check speed and norm
        exit 0
        fi
clear
echo -e  "\n${P}     ${O}༼ つ ${G}◕${R}_${G}◕ ${O}༽つ${B}${Z} A LIL PUSH_SWAP TEST ${P}"
echo -e "${R}compiling...${NO_COLOR}"
cd .. && make re >/dev/null
make clean >/dev/null
echo -e "${R}author:${NO}"
cat -e author
cd tester
echo -e "\n${B}============== ${Z2} 5 NUMBERS: ${B} (min -2, max 2)"
i=1
while [ $i -le $1 ]
do
	echo -e "${NO}$i. \c"
	./loop.sh 5 $2
	((i++))
done
echo -e "\n${B}============== ${Z2} 100 NUMBERS: ${B} (min -50, max 50)"
i=1;
while [ $i -le $1 ]
do      
        echo -e "${NO}$i. \c"
	./loop.sh 100 $2
	((i++))
done
echo -e "\n${B}============== ${Z2} 500 NUMBERS: ${B} (min -250, max 250)"
i=1
while [ $i -le $1 ]
do      
        echo -e "${NO}$i. \c"
	./loop.sh 500 $2
	((i++))
done
echo -e "\n${B}-------------------------------------------\n"
if (( $# > 1 )); then
        if [ $2 = "norm" ]; then
                echo -e "${R}NORME ERRORS:${NO}"
                cd .. && ~/.norminette/norminette.rb *.c libft *.h | grep "Error" | wc -l
cd tester
                fi
        fi
if (( $# > 2 )); then
        if [ $3 = "norm" ]; then
		echo -e "${R}NORME ERRORS:${NO}"
		cd .. && ~/.norminette/norminette.rb *.c libft *.h | grep "Error" | wc -l
cd tester
                fi
        fi
echo -e "               ${B}${Z} THE END ${NO}\n"
cd .. && make fclean >/dev/null
