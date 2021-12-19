#!/bin/bash

A=($(echo $* | tac -s " "))
B=()
let a_top=$#-1
let b_top=-1

function pb (){
	B+=(${A[$a_top]})
	unset A[$a_top]
	A=(${A[*]})
	let a_top=$a_top-1
	let b_top=$b_top+1
}

function pa (){
	A+=(${B[$b_top]})
	unset B[$b_top]
	B=(${B[*]})
	let a_top=$a_top+1
	let b_top=$b_top-1
}

function ra (){
	tmp=${A[$a_top]}
	for ((i=$a_top; i>0; i--)); do
		A[$i]=${A[$i-1]}
	done
	A[0]=$tmp
}

function rb (){
	tmp=${B[$b_top]}
	for ((i=$b_top; i>0; i--)); do
		B[$i]=${B[$i-1]}
	done
	B[0]=$tmp
}

function rr (){
	ra
	rb
}

function rra (){
	tmp=${A[0]}
	for ((i=0; i<$a_top; i++)); do
		A[$i]=${A[$i+1]}
	done
	A[$a_top]=$tmp
}

function rrb (){
	tmp=${B[0]}
	for ((i=0; i<$b_top; i++)); do
		B[$i]=${B[$i+1]}
	done
	B[$b_top]=$tmp
}

function rrr (){
	rra
	rrb
}

function sa (){
	tmp=${A[$a_top]}
	A[$a_top]=${A[$a_top-1]}
	A[$a_top-1]=$tmp
}

function sb (){
	tmp=${B[$b_top]}
	B[$b_top]=${B[$b_top-1]}
	B[$b_top-1]=$tmp
}

function ss (){
	sa
	sb
}

function print (){
	echo "========="
	for b in ${B[*]};do
		echo $b
	done
	echo "====B===="
	echo "====A===="
	for a in $(echo ${A[*]} | tac -s " ");do
		echo $a
	done
	echo "========="
}


ope=$(./push_swap $* | sed -e "s/\n/ /g")

for o in $ope;do
	clear
	echo "Before["$tmp"]"
	print
	read -p "Next["$o"]"
	if [ $o == "pb" ];then
		pb
	elif [ $o == "pa" ];then
		pa
	elif [ $o == "ra" ];then
		ra
	elif [ $o == "rb" ];then
		rb
	elif [ $o == "rr" ];then
		rr
	elif [ $o == "rra" ];then
		rra
	elif [ $o == "rrb" ];then
		rrb
	elif [ $o == "rrr" ];then
		rrr
	elif [ $o == "sa" ];then
		sa
	elif [ $o == "sb" ];then
		sb
	elif [ $o == "ss" ];then
		ss
	fi
	tmp=$o
done
clear
echo "Before["$tmp"]"
print
