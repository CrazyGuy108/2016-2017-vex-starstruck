/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * Header for the drive train program.
 *
 * Symbolic constants:
 * -LJX:        Corresponds to left joystick X.
 * -LJY:        Corresponds to left joystick Y.
 * -RJX:        Corresponds to right joystick X.
 * -RJY:        Corresponds to right joystick Y.
 * -J_MIN:      The minimum value a joystick has to be for it to be noticed.
 * -LIFT_SPEED: Defines the speed of the lift.
 *
 * Functions:
 * -int joystick(int value)
 * 	-Pass in LJX, LJY, RJX, or RJY as parameters.
 *	-Modifies the joystick value, doing any necessary calculations on it.
 *
 * Dependencies: None.
 */

#ifndef DRIVE_H
#define DRIVE_H

#define LJX (vexRT[Ch4])
#define LJY (vexRT[Ch3])
#define RJX (vexRT[Ch1])
#define RJY (vexRT[Ch2])

#define J_MIN      5
#define LIFT_SPEED 127

task
usercontrol();

int
joystick(int value);

#endif // DRIVE_H
