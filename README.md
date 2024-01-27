# Unix System Programming - My Navy
 Battleship game between two terminals using signals, project for semester 1 of the Epitech Unix System Programming module (B-PSU-100).

## Introduction
Battleship Game using Signals
Project Description
This project involves implementing a terminal version of the classic Battleship game using signals for communication between two players. The players can only communicate using the signals SIGUSER1 and SIGUSER2, and it is important to handle signal loss carefully while designing the communication protocol. The game is played on an 8x8 map, and on each turn, players must display their own positions and then their enemy's positions. The game concludes when all the ships of a player have been hit, at which point the winner is determined and the result is displayed.

## Usage
```
B-PSU-100> ./my_navy -h
USAGE
    ./my_navy [first_player_pid] navy_positions
DESCRIPTION
    first_player_pid: only for the 2nd player. pid of the first player.
    navy_positions: file representing the positions of the ships.
```

## Results
| test               | passed | results |
|--------------------|--------|---------|
| 00 - cheater       | 1/1    | 100%    |
| 01 - basic signals | 2/2    | 100%    |
| 02 - rigor        | 8/8    | 100%    |
| 03 - protocol     | 4/4    | 100%    |
| 04 - game | 8/7    | 87.5%   |
| total              | 23/22  | 95.7%   |