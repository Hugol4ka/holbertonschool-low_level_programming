# C - Doubly linked lists

## Description
This project is part of the Low-level programming curriculum. It covers the implementation and manipulation of doubly linked lists in C, including adding, deleting, and searching for nodes.

## Resources
* [Doubly linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list)

## Learning Objectives
* What is a doubly linked list
* How to use doubly linked lists
* Understand the difference between singly and doubly linked lists

## Project Structure

| File | Description |
| --- | --- |
| `lists.h` | Header file containing structures and prototypes. |
| `0-print_dlistint.c` | Prints all the elements of a `dlistint_t` list. |
| `1-dlistint_len.c` | Returns the number of elements in a linked `dlistint_t` list. |
| `2-add_dnodeint.c` | Adds a new node at the beginning of a `dlistint_t` list. |
| `3-add_dnodeint_end.c` | Adds a new node at the end of a `dlistint_t` list. |
| `4-free_dlistint.c` | Frees a `dlistint_t` list. |
| `5-get_dnodeint.c` | Returns the nth node of a `dlistint_t` linked list. |
| `6-sum_dlistint.c` | Returns the sum of all the data (n) of a `dlistint_t` linked list. |
| `7-insert_dnodeint.c` | Inserts a new node at a given position. |
| `8-delete_dnodeint.c` | Deletes the node at index `index` of a `dlistint_t` linked list. |

## Requirements
* Compiled on Ubuntu 20.04 LTS using `gcc`
* Language: C (Standard: gnu89)
* Style: Betty compliant

## Compilation
To compile the functions along with your main file:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 8-delete_dnodeint.c -o k