for i in $(seq 1 1000); do {
	echo -n $i":"
	ARG=$(jot -r -s " " 100 -2147483648 2147483647);./push_swap $ARG | ./checker_Mac $ARG; line=$(./push_swap $ARG | wc -l);
	if [ $line -ge 700 ]; then
		echo "==============================================="$line
		# exit 1
	fi
}
done
