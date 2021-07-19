#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test
##

testoutput()
{
    ./solver/solver $1 &> data
    if [[ $? == $2 ]]
    then
        echo -e "\E[0;32m \t\tTest output $3 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest output $3 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

testdisplay()
{
    ./solver/solver $1 &> data
    diff -q data $2
    if [[ $? == $3 ]]
    then
        echo -e "\E[0;32m \t\tTest display $4 \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m \t\tTest display $4 \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

echo -e "\E[0m \e[90m\e[1m SOLVER TESTS \e\e[0m"
echo -e "\E[0m \e[90m\e[1m \tBASIC TESTS, ERROR HANDLING \e\e[0m"
testdisplay "-h" "solver/tests/output/usage" "0" "usage"
testoutput "-h" "0" "usage"
testoutput "" "84" "not enoug arguments"
testdisplay "solver/tests/imput/not_sol" "solver/tests/output/not_sol" "0" "not_sol"
testdisplay "solver/tests/imput/5x5" "solver/tests/output/5x5" "0" "5x5"
testdisplay "solver/tests/imput/20x20" "solver/tests/output/20x20" "0" "20x20"

rm -f data