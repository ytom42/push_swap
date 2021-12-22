for i in $(seq 1 10000); do {
	echo -n $i":"
	ARG=$(jot -r -s " " 100 -2147483648 2147483647);./push_swap $ARG | ./checker_Mac $ARG;
}
done
