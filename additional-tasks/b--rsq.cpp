/*
# B. Range Sum Query (RSQ)

## Input File
Standard input

## Output File
Standard output

## Time Limit
2 seconds

## Memory Limit
256 megabytes

## Input
The first line contains the number `n` — the size of the array. (1 ≤ n ≤ 500,000)

The second line contains `n` numbers `a_i` — elements of the array.

The following is a description of the operations; their number does not exceed 1,000,000. Each line contains one of the following operations:

- `set i x` — set `a[i]` to `x`.
- `sum i j` — print the sum of the elements in the array in the range from `i` to `j`, it is guaranteed that (1 ≤ i ≤ j ≤ n).

All numbers in the input file and the results of all operations do not exceed $10^{18}$ in absolute value.

## Output
Print successively all the operations `sum`. Follow the output file format from the example.

## Example

standard input
```plaintext
5
1 2 3 4 5
sum 2 5
sum 1 5
sum 1 4
sum 2 4
set 1 10
set 2 3
set 5 2
sum 2 5
sum 1 5
sum 1 4
sum 2 4
```

standard output
```plaintext
14
15
10
9
12
22
20
10
```
 */