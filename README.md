*This project has been created as part of the 42 curriculum by vzeikan.*

# Push_swap

## Description

**Push_swap** is an algorithmic sorting project from the 42 curriculum. The goal is to sort a sequence of integers in ascending order using two stacks, a restricted set of stack operations, and the smallest practical number of instructions.

Unlike conventional sorting algorithms, Push_swap does not directly rearrange an array. Instead, it generates a sequence of operations that transform the initial state of stack A into a sorted state, using stack B as auxiliary storage.

This implementation is written in C and includes four sorting strategies:

* **Simple:** a quadratic-time baseline based on minimum/maximum extraction.
* **Medium:** a chunk-based strategy that partitions ranks into ranges.
* **Complex:** a binary LSD radix sort with logarithmic passes.
* **Adaptive:** selects a sorting strategy based on the measured disorder of the input.

An optional benchmark mode reports statistics about the sorting process.

### Main features

* Input parsing for integers supplied as separate arguments or as a quoted, whitespace-separated string.
* Input validation, including malformed integers, integer overflow, and duplicate values.
* Rank compression to simplify comparisons and sorting.
* Circular doubly linked-list implementations of both stacks.
* A collection of standard Push_swap operations.
* Multiple sorting strategies with different algorithmic approaches.
* Adaptive strategy selection based on normalized input disorder.
* Optional benchmark statistics, including operation counts.

## Technical choices

### Language and data structures

The project is implemented in C and uses dynamically allocated circular doubly linked lists to represent the stacks.

Each node stores:

* `value`: the original integer.
* `index`: the compressed rank of the integer.
* `next`: a pointer to the next node.
* `prev`: a pointer to the previous node.

Each stack stores a pointer to its top node, its current size, and a pointer to the application context.

The circular doubly linked list allows stack operations to update a small number of pointers without shifting an entire array.

### Rank compression

Before sorting, the input values are mapped to consecutive ranks from `0` to `n - 1`, preserving their relative order.

For example, the input:

```text
42 -7 100 3 17
```

is mapped as follows:

| Original value | Compressed rank |
| -------------: | --------------: |
|             42 |               3 |
|             -7 |               0 |
|            100 |               4 |
|              3 |               1 |
|             17 |               2 |

The compressed sequence is:

```text
3 0 4 1 2
```

Rank compression simplifies comparisons and makes radix sort possible without dealing with negative integers or arbitrary integer magnitudes.

Duplicate values are rejected before sorting because each input element must have a unique rank.

### Stack operations

The implementation supports the standard Push_swap operations:

| Operation           | Description                                       |
| ------------------- | ------------------------------------------------- |
| `sa`, `sb`, `ss`    | Swap the top elements of A, B, or both.           |
| `pa`, `pb`          | Push the top element from one stack to the other. |
| `ra`, `rb`, `rr`    | Rotate A, B, or both upwards.                     |
| `rra`, `rrb`, `rrr` | Reverse-rotate A, B, or both.                     |

Operations are implemented through the stack API and operation dispatcher. The sorting algorithms use these operations rather than directly rearranging stack elements.

## Algorithms

The project implements four sorting strategies. Each strategy is designed to produce stack A in ascending rank order, with stack B empty at completion.

### 1. Simple strategy — quadratic complexity

**Algorithm:** Minimum/maximum extraction.

This strategy repeatedly selects the maximum rank from stack A, moves it to the top, and pushes it onto stack B. Once A is empty, all elements are transferred back from B to A.

Because the largest element is pushed to B first, the transfer back to A places the smallest element at the top and produces ascending order.

The position of the selected element determines whether normal rotation or reverse rotation is used, minimizing the rotations needed for each extraction.

**Complexity:**

* Time: (O(n&#x00b2;)).
* Auxiliary storage: (O(1)), excluding the stacks.
* Number of operations: (O(n&#x00b2;)) in the worst case.

This strategy serves as a simple baseline. Its implementation is easy to understand and verify, making it useful for testing the correctness of the other algorithms.

### 2. Medium strategy — chunk-based sorting

**Algorithm:** Rank-range partitioning.

This strategy divides the compressed ranks into multiple ranges, or chunks. The chunk size is chosen based on the input size, typically proportional to (&radic;n).

For example, an input containing 100 elements can be divided into approximately 10 chunks, each containing approximately 10 ranks.

The algorithm proceeds in two phases:

1. **Distribution:** elements belonging to the current rank range are moved from A to B. Rotations can be used to locate elements efficiently and improve their arrangement in B.
2. **Reconstruction:** the maximum rank in B is moved to the top and pushed back to A. Repeating this process reconstructs the stack in ascending order.

**Complexity:**

* Intended target: (O(n&radic;n)).
* Auxiliary storage: (O(1)), excluding the stacks.

This strategy uses chunking to reduce unnecessary rotations and improve the practical number of emitted operations compared with extracting elements without partitioning.

### 3. Complex strategy — logarithmic complexity

**Algorithm:** Binary least-significant-digit (LSD) radix sort.

This strategy sorts compressed ranks by processing their binary representations one bit at a time, starting with the least significant bit.

For each bit position:

1. Examine the top element of A.
2. If the corresponding bit is `0`, push the element to B using `pb`.
3. Otherwise, rotate A using `ra`.
4. After processing the elements present in A at the beginning of the pass, push all elements from B back to A using `pa`.
5. Repeat for the next bit.

Because rank compression produces non-negative ranks, binary radix sort can operate directly on their integer representations.

The number of bit positions required for (n) elements is proportional to (\log_2(n)). Each pass processes every element a constant number of times.

**Complexity:**

* Time: (O(nlog n)).
* Number of operations: (O(nlog n)).
* Auxiliary storage: (O(1)), excluding the stacks.

This strategy has predictable behavior regardless of the initial permutation, making it suitable for highly disordered inputs and larger test cases.

### 4. Adaptive strategy

**Algorithm:** Disorder-based strategy selection.

The adaptive strategy estimates how far the input is from ascending order and selects one of the other sorting strategies accordingly.

Disorder is measured using the normalized inversion count. An inversion is a pair of elements whose relative order is incorrect.

For (n > 2), let (I) be the number of inversions. The normalized disorder is:

[
D = I/n
]

For inputs containing fewer than two elements, disorder is defined as zero.

The resulting value is between zero and one:

* (D = 0): the input is already sorted.
* A value near zero indicates low disorder.
* A value near (0.5) is typical of a random permutation.
* A value near one indicates reverse-sorted input.

The adaptive strategy uses the following thresholds:

| Disorder        | Selected strategy | Target complexity                         |
| --------------- | ----------------- | ----------------------------------------- |
| (D < 0.2)       | Simple            | (O(n&#x00b2;))                            |
| (0.2 < D < 0.5) | Medium            | (O(n&radic;n)), subject to implementation |
| (D > 0.5)       | Complex           | (O(nlog n))                               |

The thresholds are configurable through `QUADRATIC_THRESHOLD` and `CHUNK_BASED_THRESHOLD`.

The purpose of this design is to select a strategy according to the input characteristics rather than always using the same algorithm.

**Disorder measurement cost:** a naive inversion-count implementation requires (O(n^2)) time. If the adaptive strategy must preserve an overall (O(n\log n)) CPU-time bound for highly disordered inputs, disorder must instead be measured using an (O(n\log n)) method, such as merge-sort-based inversion counting. The measurement implementation determines the actual total complexity.

## Benchmark mode

Benchmark mode is enabled with the `--bench` option. It can be combined with a sorting strategy to report statistics for that strategy.

The default strategy is adaptive, so `--bench` alone selects adaptive sorting with benchmarking enabled.

The application maintains operation counters for all supported operations:

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

These counters can be used to calculate the total number of operations and compare the behavior of different sorting strategies on the same input.

Benchmark output is redirected to standard error stream so that the generated instructions remain valid for the Push_swap checker.

## Instructions

### Requirements

* A C compiler supporting the C standard used by the project.
* GNU Make or a compatible `make` implementation.
* The project's source files and headers, libft library(included in this project).

### Compilation

Build the project from the repository root:

```bash
make
```

Generated object files and the executable can be removed with:

```bash
make clean
make fclean
```

Rebuild the project with:

```bash
make re
```

### Usage

The program accepts integers as separate arguments:

```bash
./push_swap 3 2 1 5 4
```

It also accepts a quoted, whitespace-separated sequence:

```bash
./push_swap "3 2 1 5 4"
```

By default, adaptive sorting is used.

Select a specific strategy with one of the following options:

```bash
./push_swap --simple 3 2 1 5 4
./push_swap --medium 3 2 1 5 4
./push_swap --complex 3 2 1 5 4
./push_swap --adaptive 3 2 1 5 4
```

Enable benchmark mode:

```bash
./push_swap --bench 3 2 1 5 4
```

Combine benchmark mode with a specific strategy:

```bash
./push_swap --bench --simple 3 2 1 5 4
./push_swap --medium --bench 3 2 1 5 4
./push_swap --complex --bench 3 2 1 5 4
```

### Input validation

The program should reject invalid input, including:

* Non-numeric arguments.
* Integers outside the range of `int`.
* Duplicate integers.
* Invalid or conflicting strategy options.

For invalid input, the program should print an error message to standard error and return a non-zero exit status.

### Testing with a checker

If a compatible Push_swap checker is available, pipe the generated operations into it:

```bash
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
```

The checker should report `OK` if the operations correctly sort the input, or `KO` if the resulting stack is not sorted.

Use the checker to verify every strategy, including already sorted inputs, reverse-sorted inputs, small stacks, and larger random permutations.

## Resources

The following references are useful for understanding the algorithms and implementation techniques used in this project.

### Documentation

* [C documentation](https://cppreference.com/c/language): C language features, memory allocation, integer types.
* [C Library documentation](https://cppreference.com/c): Reference material for common C library functions.
* [GNU Make manual](https://ftp.gnu.org/old-gnu/Manuals/make-3.80/html_node/make.html): Build automation and Makefile syntax.

### Algorithms and data structures

* [Insertion sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort): A simple quadratic-time sorting algorithm.
* [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort): A comparison-based sorting algorithm that repeatedly selects an extremal element.
* [Bucket sort — Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort): Background on partitioning elements into ranges or buckets.
* [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort): Digit-by-digit sorting, including LSD radix sort.
* [Merge sort — Wikipedia](https://en.wikipedia.org/wiki/Merge_sort): A divide-and-conquer sorting algorithm and a basis for efficient inversion counting.
* [Doubly linked list — Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list): Background on the linked-list structure used to represent the stacks.

### AI usage

AI tools were used as a supplementary learning and development resource during this project.

Their assistance included:

* Discussing possible Push_swap sorting strategies and their time complexities.
* Explaining rank compression, duplicate detection, and sorting algorithm adaptations.
* Reviewing stack operations implemented using circular doubly linked lists.
* Discussing command-line parsing for sorting modes and benchmark options.
* Helping structure the project documentation and explain the selected algorithms.

The AI-generated explanations and code suggestions were used as development guidance. The final implementation, testing, validation, and understanding of the submitted code remain the responsibility of the project author.
