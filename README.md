# Unix System Programming - My Navy
 Battleship game between two terminals using signals, project for semester 1 of the Epitech Unix System Programming module (B-PSU-100).

## Introduction
This project involves implementing a terminal version of the classic Battleship game using signals for communication between two players. The players can only communicate using the signals SIGUSER1 and SIGUSER2, and it is important to handle signal loss carefully while designing the communication protocol. The game is played on an 8x8 map, and on each turn, players must display their own positions and then their enemy's positions. The game concludes when all the ships of a player have been hit, at which point the winner is determined and the result is displayed.

The full description of the project can be found in [subject.pdf](pdf/B-PSU-100_my_navy.pdf).

## Prerequisites
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)
 - [LibC](https://www.gnu.org/software/libc/)

## Installation
```
B-PSU-100> git clone git@github.com:WilliamJlvt/my_navy.git
...
B-PSU-100> make
...
```

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
| test                | passed | results |
|---------------------|--------|---------|
| 00 - cheater        | 1/1    | 100%    |
| 01 - basic signals  | 2/2    | 100%    |
| 02 - rigor          | 8/8    | 100%    |
| 03 - protocol       | 4/4    | 100%    |
| 04 - game           | 8/7    | 87.5%   |
| total               | 22/23  | 95.7%   |

## Coding style
All the source code has been written according to the [Epitech C Coding Style](https://williamjlvt.github.io/assets/coding_style/epitech_c_coding_style.pdf).
#### errors
| Fatal | Major  | Minor | Info |
|-------|--------|-------|------|
| 0     | 0      | 0     | 0    |

## Authors
* **William JOLIVET** ([GitHub](https://github.com/WilliamJlvt) / [LinkedIn](https://www.linkedin.com/in/william-jolivet-64951a24b/))
* **Florian REYNAUD** ([GitHub](https://github.com/FLOWleplusbeau))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
