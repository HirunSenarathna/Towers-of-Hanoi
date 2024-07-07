# Towers of Hanoi Game

The Towers of Hanoi is a classic puzzle game that involves moving a stack of disks from one rod to another while following specific rules. This C++ program implements the Towers of Hanoi game and provides a text-based interface for players to interact with.

## Table of Contents

- Overview
- Features
- How to Play
- Instructions
- Requirements
- Installation
- Usage
- Members
## Overview

The Towers of Hanoi game is a puzzle where you have three rods labeled A, B, and C. The goal is to move a stack of disks from rod A to rod C, following these rules:

1. You can only move one disk at a time.
2. You cannot place a larger disk on top of a smaller disk.
3. You can use the auxiliary rod as a helping rod.
4. Rod names must be entered in uppercase.

The game keeps track of the number of moves you make, and your objective is to complete the puzzle in the minimum number of moves possible.

## Features

- Interactive text-based interface.
- Option to choose the number of disks.
- Option to play with a random number of disks (between 3 and 7).
- Checks for valid moves and warns against illegal moves.
- Displays the current state of the towers.
- Provides instructions on how to play the game.

## How to Play

1. Choose the number of disks or play with a random number of disks.
2. Follow the on-screen instructions to make moves.
3. Enter the source and destination rod for each move (e.g., "A C").
4. The game will display the current state of the towers and the number of moves.
5. Your goal is to move all the disks to rod C following the rules.
6. Once you complete the puzzle, the game will congratulate you and display the number of moves it took.

## Instructions

To play the game, follow these instructions:

- Use the keyboard keys A, B, C to represent the rod names.
- Enter "Shift" or enable "Caps Lock" to capitalize rod names.
- Press "Enter" to make a move.
- If you attempt an invalid move, the game will notify you.

## Requirements

- C++ compiler
- Windows operating system (due to the use of `conio.h` for console input/output)

## Installation

1. Clone or download the repository to your local machine.
2. Compile the C++ source code using a C++ compiler.
3. Run the executable to start the game.

## Usage

1. Launch the game.
2. Choose the number of disks or play with a random number of disks.
3. Follow the on-screen instructions to make moves.
4. Complete the puzzle by moving all disks to rod C in the minimum number of moves.


