# 2016-17 Vex Starstruck Competition Code
This is the competition code for Team 1516B's (California High School) robot for the 2016-17 Vex Starstruck competition.
It can be compiled and ran using RobotC on a VEX ARM Cortex, provided you have the robot to run it on as well.
## Contents
The directory contains 3 main pairs of sources/headers:
* [Auto](auto.c): The autonomous program.
* [Drive](drive.c): The user control code.
* [Lib](lib.c): Helper functions that apply to both.

The [main.c](main.c) file, because RobotC only allowed me to compile one C file at a time, includes all those other C files and sets up a bunch of configurations.
There's also a [revisions](revisions/) folder, which contains revisions that were made after the competition.
## License
This project is under the MIT license, which can be found [here](LICENSE).
