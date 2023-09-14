# Parallel Programming Course Labs

This repository contains my implementations for the labs in the Parallel Programming course.

## Lab 1: Producer-Consumer Problem using OpenMP

In this lab, a classic parallel computing problem is implemented, the Producer-Consumer problem, using OpenMP. The goal is let multiple producer threads read lines from different input files and enqueue them into a shared queue, while multiple consumer threads simultaneously dequeue lines from the queue and process them. Specifically, consumers split the lines and print the results to the standard output.

## Lab 2: Multi-Process Odd-Even Sort using MPI

In Lab 2, through Message Passing Interface (MPI) a multi-process odd-even sort algorithm is implemented. This algorithm efficiently sorts an array across multiple processes by performing a series of parallel comparisons and swaps.