## To do next:

- [ ] Remove comments + norm check
- [ ] Split normalize input in split_input e join_input
- [ ] Must reject empty string in the middle of valid ones?
- [ ] Not printing error for int over/underflow
- [ ] Fix validation errors (use validation_tester.sh)
- [ ] Organize 'srcs' in subdirs + update Makefile accordingly
- [ ] Handle edge case of rev_sorted (call is_revsorted + rotate_stack)
- [ ] README.md

## To do later:

- [ ] A LOT of tests (print intermediate sorting states)
- [ ] Replace int for size_t/ssize_t for counters, indexes, sizes, etc.
- [ ] 42 HEADERS!! Check libft functions for missing headers too! Or pther issues
- [ ] Test validation better!!!
- [ ] Check for unused files and functions, nice repo cleanup

---

## Done:

- [X] Merge helpers.h and push_swap.h in a single header file
- [X] Implement rotate_stack + is_revsorted
- [X] finish push_swap() function
- [X] New main
- [X] Test set_target and find_min
- [X] Test new functions
- [X] Cost calculation
- [X] Find_target
- [X] Sort_4 function
- [X] Push_swap function that: calls is_sorted, sort 2, 3, 4, 5 or the actual alg.
- [X] Test sorting functions so far
- [X] Is_sorted function
- [X] Norminette round
- [X] New main
- [X] Test list-related + new validation functions
- [X] Implement sort 2, 3 and 5 functions
- [X] Replace safe_aotoi (too long!) with ft_atol + check for int limits
- [X] missing reverse rotate
- [X] Generic push and rotate functions
- [X] list_utils + modify some libft_bonus functios
- [X] Redo validation (first, parse av to tokens, then validate each token)
- [X] Take notes 
- [X] Create pre-gitignore
- [X] Write main and input validation functions 
- [X] Write 'rules' secction
- [X] Find out how to include libft + on the Makefile
- [X] Makefile
- [X] Replace libft strjoin with piscine's strjoin + same for ft_split(??)
- [X] Add check for repeated nums in validation
- [X] Write free_stack()
 
---

## Take notes on:

- [X] Each operation
- [ ] Big O Notation
- [ ] Algorithm types
- [ ] More details on the chosen algorithm

---

## Final checks:

- [ ] Norm check
- [ ] Search unwanted files
- [ ] Remove forbiden functions

---

## Rules
- [X] Must have Makefile (it must not relink)
- [ ] The first argument should be at the top of the stack
- [ ] must display the shortest sequence of instructions needed to sort stack
      a with the smallest number at the top
- [ ] Instructions must be separated by a ’\n’ and nothing else
- [ ] If no parameters are specified, the program simply returns
- [X] In case of error, it must display "Error" followed by an ’\n’ on the standard error

---

## Questions:

- Does ir really makes sense to keep sort_4 and 5 functions?
- Should it really do nothing if the stack is sorted? I think so
- Can I really have my subdirectories?
- How do I include libft and ft_printf?
