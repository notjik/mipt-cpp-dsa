/*
# A. Range Minimum Query (RMQ)

## Input File
Standard input

## Output File
Standard output

## Time Limit
8 seconds

## Memory Limit
256 megabytes

## Input
The first line contains the number `n` — the size of the array. (1 ≤ n ≤ 500,000)

The second line contains `n` numbers `a_i` — elements of the array.

The following is a description of the operations; their number does not exceed 1,000,000. Each line contains one of the following operations:

- `set i x` — set `a[i]` to `x`.
- `min i j` — print the value of the minimum element in the array between `i` and `j`, it is guaranteed that (1 ≤ i ≤ j ≤ n).

Only integers are placed in the array that do not exceed $10^9$ in absolute value.

## Output
Print successively all the operations `min`. Follow the output file format from the example.

## Example
standard input
```plaintext
5
1 2 3 4 5
min 2 5
min 1 5
min 1 4
min 2 4
set 1 10
set 2 3
set 5 2
min 2 5
min 1 5
min 1 4
min 2 4
```

standard output
```plaintext
2
1
1
2
2
2
3
3
```
 */
#include <cstring>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  char* op = new char[4];
  while (std::cin >> op) {
    if (!strcmp(op, "set")) {
      int i, x;
      std::cin >> i >> x;
    } else if (!strcmp(op, "min")) {
      int i, j;
      std::cin >> i >> j;
    } else {
      break;
    }
  }
  delete[] arr;
  delete[] op;
  return 0;
}

