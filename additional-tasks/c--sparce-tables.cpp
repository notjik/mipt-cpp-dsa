/*
# C. Sparse Tables

## Time Limit
2 seconds

## Memory Limit
256 megabytes

## Input
Standard input or input.txt

## Output
Standard output or output.txt

## Task
Given an array of `n` numbers, you need to write a program that will respond to queries of the following type: find the minimum in the segment between `u` and `v`, inclusive.

## Input Format
The first line contains three natural numbers `n`, `m` (1 ≤ n ≤ 10^5, 1 ≤ m ≤ 10^7) and `a_1` (0 ≤ a_1 < 16714589) — the number of elements in the array, the number of queries, and the first element of the array, respectively. The second line contains two natural numbers `u_1` and `v_1` (1 ≤ u_1, v_1 ≤ n) — the first query.

To keep the input size small, the array and queries are generated. The elements `a_2`, `a_3`, ..., `a_n` are defined by the following formula:

$$a_{i+1} = (23 \cdot a_i + 21563) \mod 16714589$$

For example, with `n = 10` and `a_1 = 12345`, the array `a` is (12345, 305498, 7048017, 11694653, 1565158, 2591019, 9471233, 570265, 13137658, 1325095).

Queries are generated as follows:

$$u_{i+1} = ((17 \cdot u_i + 751 + r_i + 2i) \mod n) + 1$$
$$v_{i+1} = ((13 \cdot v_i + 593 + r_i + 5i) \mod n) + 1$$

where `r_i` is the answer to query number `i`. Note that `u_i` can be greater than `v_i`.

## Output Format
In the output file, print `u_m`, `v_m` and `r_m` (the last query and the answer to it).

## Example
Input:
```
10 8 12345
3 9
```
Output:
```
5 3 1565158
```

## Notes
You can notice that the arrays `u`, `v` and `r` do not need to be fully stored in memory. Queries and their responses look like this:

```
i   u_i   v_i   r_i
1   3     9     570265
2   10    1     12345
3   12    2     12345
4   10    10    1325095
5   5     9     570265
6   21    12    12345
7   32    30    305498
8   53    31    1565158
```
 */