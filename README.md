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

- [👨‍🏫 Demonstration](#-demonstration)
- [📚 Table of Contents](#-table-of-contents)
- [📦 Installation](#-installation)
- [📝 Usage](#-usage)
- [📝 Example](#-example)
- [📎 Algorithm](#-algorithm)

## 👨‍🏫 Demonstration

Here's how the algorithm works with 500 random values.

https://user-images.githubusercontent.com/103316367/223166941-7241bbfe-ab47-43ad-abc3-97519f68176c.mp4

> The visualizer used: https://github.com/o-reo/push_swap_visualizer

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
> The program will wait for you to enter instructions to sort the stack. You can also pipe the instructions of the sorting program to the checker program like below. When you're done entering instructions, don't just press enter, type `CTRL + D` to end the program.

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

## 📎 Algorithm

The algorithm used to sort a stack of 100 and 500 numbers is based on the [Quick Sort](https://en.wikipedia.org/wiki/Quicksort) algorithm. It's a divide and conquer algorithm that sorts a stack by splitting it into smaller stacks, sorting them and then merging them back together.
Here you can find the [article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) that explains how the algorithm works and how to implement it.

Implementing this algorithm won't get you the highest grade (aka. 100/100) because you have to optimize it and I'll explain how I managed to do it. The goal here is to sort 100 numbers in less than 700 moves and 500 numbers in less than 5500 moves.

> First optimization

To do so, when pushing a number from the stack A to the stack B, I check if the number is smaller than the median of its chunk. If it is, I push it to the stack B (pb) then I rotate the stack B (rb) to put the number at the bottom of the stack. If it's not, I simply push it to the stack B (pb). 
When the stack A is empty, I then search for the two biggest numbers in the stack B and push them to the stack A (pa) depending on their position (index). If they aren't pushed in the right order, I simply swap them (sa). Finally, I repeat the process until the stack B is empty.

> Second optimization

When printing the instructions to sort the stack, sometimes you can find a sequence of instructions that can be replaced by a single instruction. For example, if you have to rotate the stack A (ra) and then rotate the stack B (rb), you can simply print one instruction (rr).
To do so, I created a function that makes the instructions asynchronic. It means that if you call an instruction, it will wait for the next instruction to be called before printing it. If the next instruction and the previous one can be replaced by a single instruction, it will print it instead of the two instructions. If not, it will simply print the previous instruction and the current one.
You can find this function in the `srcs/ft_instructions_printer.c` file.

[⬆ Back to Top](#-table-of-contents)

## 🌏 Meta

bsoubaig – bsoubaig@student.42nice.fr
