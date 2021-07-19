#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test
##

testoutput()
{
    ./generator/generator $1 $2 $3 &> data
    if [[ $? == $4 ]]
    then
        echo -e "\E[0;32m \t\tTest output $5 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest output $5 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

testdisplay()
{
    ./generator/generator $1 $2 $3 &> data
    diff -q data $4
    if [[ $? == $5 ]]
    then
        echo -e "\E[0;32m \t\tTest display $6 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest display $6 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

echo -e "\E[0m \e[90m\e[1m GENERATOR TESTS \e\e[0m"
echo -e "\E[0m \e[90m\e[1m \tBASIC TESTS, ERROR HANDLING \e\e[0m"
testdisplay "-h" "" "" "generator/tests/output/usage" "0" "usage"
testoutput "-h" "" "" "0" "usage"
testoutput "" "" "" "84" "no arguments"
testoutput "1" "" "" "84" "not enough arguments"
testoutput "1" "a" "perfect" "84" "argument y is not num"
testoutput "0" "1" "perfect" "84" "argument x is 0"
testoutput "4" "-5" "" "84" "argument y is negative"
testoutput "4" "5" "parfact" "84" "argument perfect is not good string"

rm -f data