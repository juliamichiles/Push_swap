#!/bin/sh

PS=./push_swap

run_error_test()
{
    desc="$1"
    shift
    $PS "$@" > /dev/null 2> err.txt
    if grep -q "Error" err.txt; then
        echo "[OK]   $desc"
    else
        echo "[FAIL] $desc"
    fi
}

run_valid_test()
{
    desc="$1"
    shift
    $PS "$@" > /dev/null 2> err.txt
    if grep -q "Error" err.txt; then
        echo "[FAIL] $desc"
    else
        echo "[OK]   $desc"
    fi
}

echo "=== DUPLICATES ==="
run_error_test "duplicate numbers" 1 2 2 3
run_error_test "duplicate negatives" -3 -3 -2
run_error_test "same number twice" 5 5

echo "\n=== NON NUMERIC ==="
run_error_test "letter inside" 1 a 2
run_error_test "float number" 3 4.5 6
run_error_test "mixed string" 1 2 three
run_error_test "double sign" ++1 2
run_error_test "broken number" 1-2 3

echo "\n=== INVALID SIGNS ==="
run_error_test "single plus" +
run_error_test "single minus" -
run_error_test "plus minus" +-1
run_error_test "minus plus" -+1

echo "\n=== OVERFLOW ==="
run_error_test "int max overflow" 2147483648
run_error_test "int min overflow" -2147483649
run_error_test "huge number" 999999999999

echo "\n=== EMPTY / WEIRD ==="
run_error_test "empty string" ""
run_error_test "spaces only" "   "
run_error_test "empty arg inside" 1 "" 2
run_error_test "invalid split" "1 2 2 3"

echo "\n=== VALID INPUTS ==="
run_valid_test "single number" 1
run_valid_test "already sorted" 1 2 3
run_valid_test "reverse order" 3 2 1
run_valid_test "signed numbers" +1 -2 3
run_valid_test "string input" "3 2 1"
run_valid_test "spaced string" "  3   -2   +1  "

