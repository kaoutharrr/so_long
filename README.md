# so_long Project

## Table of Contents
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Game Rules](#game-rules)
- [Assets](#assets)
- [Project Structure](#project-structure)
- [Setup and Compilation](#setup-and-compilation)
- [Usage](#usage)
- [Example](#example)
- [Error Handling](#error-handling)
  
## Introduction
**so_long** is a small 2D game project developed as part of the **42 curriculum**. The goal is to build a simple game where the player must collect items and reach an exit on a map, all while avoiding certain obstacles. The project requires handling events such as keyboard input and rendering a graphical window using the **MiniLibX** library.

## Objectives
- Create a basic 2D game using **MiniLibX**.
- Implement proper event handling (keyboard and window events).
- Display the map using textures and move the player character on keypresses.
- Collect all collectibles before reaching the exit to win the game.
- Handle errors like invalid map input or memory leaks.

## Game Rules
- The player moves through a map represented by a grid of characters.
- The player must collect all items (represented by `C`) on the map before reaching the exit (`E`).
- The game features obstacles or walls (`1`) that block the player’s movement.
- The empty spaces where the player can move are represented by `0`.
- The player starts at the position marked by `P`.

### Key Points:
- The player can move **up, down, left, or right**.
- The number of moves should be displayed in the terminal after each movement.
- The game will end when the player reaches the exit after collecting all the items.

## Textures
- **Textures/Sprites**:
  - Each tile on the map (e.g., player, collectible, wall, floor) must have a corresponding texture.
  - MiniLibX will be used to load and render these images.
  
  Common textures include:
  - `P` - Player character sprite
  - `C` - Collectibles (items to be gathered)
  - `E` - Exit (the end goal)
  - `1` - Walls (obstacles)
  - `0` - Floor (empty spaces where the player can move)

## Setup and Compilation

### Prerequisites
- **MiniLibX**: You must have the MiniLibX library installed to create the window and handle graphics.
- **Make**: Use a Makefile to compile the project.
  
### Compilation
To compile the project, run:
```bash
make
```
This will generate the so_long executable.

### Usage
To run the game, provide a valid map file as an argument:

```bash
./so_long path_to_map_file.ber
```
#### Map Format

- The map file should be a **.ber** file (plain text).
- The map must be rectangular and surrounded by walls (`1`).
- The map must contain:
  - At least one `P` (player start position).
  - At least one `C` (collectible).
  - One `E` (exit).
C (collectible).
One E (exit).
Example of a valid map:
```bash
  111111
  1P0C01
  101101
  1C0E01
  111111
```
### Example
Run the game with a sample map:
```bash
./so_long maps/map.ber
```
### Sample Output
When the game starts, a window will open displaying the map and the player sprite.
The number of moves will be shown in the terminal.
The game will close when the player successfully collects all collectibles and reaches the exit.

## Error Handling

Your program must handle errors such as:

- Invalid file format (non `.ber` files).
- Non-rectangular maps.
- Maps missing required characters (`P`, `C`, or `E`).
- Memory leaks (use tools like **valgrind** to test).

If an error occurs, the program should display an appropriate error message and exit cleanly.
























