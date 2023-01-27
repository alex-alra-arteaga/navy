# navy
Recreation of Battleship game on 2 terminals, communicated with unix signals.

Compile with make at the root of the repository.

The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions.
At the end of the game (when all the ships of a player havebeen hit), displayS whether “I won” (and return 0) or “Enemy won” (and return 1).

In first terminal run './navy transmission/pos1.txt', then:
In second terminal run './navy [pid displayed in 1st terminal] transmission/pos2.txt'.

You are free to change ship positions in pos1 and pos2 files, if they make no sense, program will terminate as soon is executed.

Run './navy -h' to see usage.

![vokoscreenNG-2023-01-27_08-11-42 (online-video-cutter com)](https://user-images.githubusercontent.com/108436798/215096022-37e962cc-60db-49f5-ab9c-aaa1fb122067.gif)
