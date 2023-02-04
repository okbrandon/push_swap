<h1 align="center">📚 push_swap</h1>

<p align="center">
	<b><i>Push_swap is a 42 school project that consists in creating a program that sorts a stack of integers with the help of a second stack, using a limited set of instructions.</i></b><br>
</p>

<p align="center">
	<img alt="Top used language" src="https://img.shields.io/github/languages/top/okbrandon/push_swap?color=success"/>
	<img alt="Norminette run" src="https://github.com/okbrandon/push_swap/actions/workflows/42-norminette.yml/badge.svg"/>
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/okbrandon/push_swap"/>
</p>

## 📚 Table of Contents

- [📎 Algorithm](#-algorithm)
- [📚 Table of Contents](#-table-of-contents)
- [📦 Installation](#-installation)
- [📝 Usage](#-usage)
- [📝 Example](#-example)

## 📎 Algorithm

The algorithm used to sort a stack of 100 and 500 numbers is based on the [Quick Sort](https://en.wikipedia.org/wiki/Quicksort) algorithm. It's a divide and conquer algorithm that sorts a stack by splitting it into smaller stacks, sorting them and then merging them back together.
Here you can find the [article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) that explains how the algorithm works and how to implement it.

## 📦 Installation

Clone the repository from GitHub:
```sh
git clone https://github.com/okbrandon/push_swap.git
```

Compile the `push_swap` executable:
```sh
make
```

Compile the `checker` executable:
```sh
make bonus
```

## 📝 Usage

Run the sorting program:
```sh
./push_swap [numbers]
```
> The first number of your input is at the top of the stack by default. The program will print the instructions to sort the stack.

Run the checker program:
```sh
./checker [numbers]
```
> The program will wait for you to enter instructions to sort the stack. You can also pipe the instructions of the sorting program to the checker program like below.

## 📝 Example

Sorting algorithm:
```sh
$> ./push_swap 8 9 2 3 1
rra
pb
ra
ra
pb
pa
pa
```

Checker program:
```sh
$> ARG="8 9 2 3 1"; ./push_swap $ARG | ./checker $ARG
OK
```
> The checker returns OK when the stack is sorted. It'll return KO if the stack isn't sorted or if the second stack's not empty.

[⬆ Back to Top](#-table-of-contents)

## 🌏 Meta

bsoubaig – bsoubaig@student.42nice.fr