# push_swap

## Description  
**push_swap** is an algorithmic project that consists of sorting a stack of integers with a limited set of operations, using the fewest moves possible. The program receives an unsorted list of integers as input, then outputs a sequence of instructions to sort them efficiently.  

## Objectives  
- Sort a stack (`stack a`) in ascending order using a secondary stack (`stack b`).  
- Minimize the number of operations required to achieve a sorted order.  
- Handle input errors such as non-numeric values, duplicates, or numbers exceeding the integer range.  

## Allowed Operations  
The following operations can be used to manipulate the stacks:  

### Swap Operations  
- `sa` → Swap the first two elements of `stack a`.  
- `sb` → Swap the first two elements of `stack b`.  
- `ss` → Perform `sa` and `sb` simultaneously.  

### Push Operations  
- `pa` → Push the first element of `stack b` onto `stack a`.  
- `pb` → Push the first element of `stack a` onto `stack b`.  

### Rotate Operations  
- `ra` → Rotate `stack a` upwards (first element becomes last).  
- `rb` → Rotate `stack b` upwards (first element becomes last).  
- `rr` → Perform `ra` and `rb` simultaneously.  

### Reverse Rotate Operations  
- `rra` → Reverse rotate `stack a` (last element becomes first).  
- `rrb` → Reverse rotate `stack b` (last element becomes first).  
- `rrr` → Perform `rra` and `rrb` simultaneously.  

## Error Handling  
- The program prints `"Error\n"` and exits if:  
  - Any input contains non-numeric characters.  
  - Numbers exceed the range of a 32-bit integer.  
  - Duplicate numbers are found.  

## Installation  
Compile the program using:  
```sh
make
```
This will generate the `push_swap` executable.  

## Usage  
Run the program with a list of integers as arguments:  
```sh
./push_swap 4 67 3 87 23
```
The output will be a sequence of operations to sort the given numbers.  

## Example  
```sh
$ ./push_swap 3 2 1
sa
rra
```
