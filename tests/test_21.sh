for perm in \
"2 3 4 1" \
"3 4 2 1" \
"4 2 3 1" \
"4 3 2 1"
do
    echo "Testing: $perm"
    ./push_swap $perm | wc -l
done
