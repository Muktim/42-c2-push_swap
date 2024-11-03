# 42-c2-push_swap
Integer sorting algorithm using 2 stacks and tears

## **How to run**

Compile the code running the `make` command.

Type `./push_swap` in the terminal while you are in the same directory as the executable followed by integers to be sorted.

## **Important Notes**
- This project requires LIBFT to compile. Alternatively, custom functions can be replaced with built-in or standard C functions.
- If LIBFT is saved anywhere but its subfolder under the cwd (current working directory), the header file and the Makefile must be updated with the correct paths.
- The current version does not process numbers if they are grouped in quotation marks. E.g. `./push_swap 5 2 9 12` is valid but `./push_swap 5  "2 9" 12` is not valid.

## **Description**
Push swap is a sorting algorithm based on "gradient descent" and "Turk Sort" algorithms designed to sort numbers within the `int` range in "Stack A" using 2 stacks.
The algorithm is optimised for up to 500 integers using the following operations;
```
sa: Swap A - Swaps the position of the top 2 elements in Stack A
sb: Swap B - Swaps the position of the top 2 elements in Stack B
ss: Swap Both - sa and sb commands together
pa: Push A - Pushes the top element of Stack B to the top of Stack A
pb: Push B - Pushes the top element of Stack A to the top of Stack B
ra: Rotate A - Rotates the stack A where the first element becomes the last
rb: Rotate B - Rorates the stack B where the first element becomes the last
rr: Rotate Both - ra and rb commands together
rra: Reverse Rotate A - Reverse rotates the stack A where the last element becomes the first
rrb: Reverse Rotate B - Reverse rotates the stack B where the last element becomes the first
rrr: Reverse Rorate Both - rra and rrb commands together
```



#### **Notes**
    Written by Muktim in 42London
    Submitted on 29/06/2024
    Final Grade: 100/100
