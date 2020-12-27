#!/bin/bash
G='\033[0;32m'
R='\033[0;31m'
O='\033[0;33m'
P='\033[0;35m'
B='\033[0;34m'
C='\033[0;36m'
W='\033[0;37m'
Z='\033[48;5;049m'
Z2='\033[48;5;227m'
C='\033[0;36m'
NO_COLOR='\033[0m'
((min=-$1/2))
((max=$1/2))
printf "\r\t"
echo -e "${B}\c"
#printf "range: %d - %d " $min $max
#echo -e "${G}\c"
#printf "\r\t\t\t\t"
echo -e "${O}\c"
printf "RESULT:${G} "
ARG=$(printf '%s ' `seq $min $max | sort -R`); ../push_swap $ARG | ../checker $ARG -z

if (( $# > 1 )); then
	if [ $2 = "time" ]; then
		echo -e "${C}time \c"
		{ time ../push_swap $ARG >/dev/null; } 2>&1 | grep real | awk '{print $2}'
            	fi
	fi
