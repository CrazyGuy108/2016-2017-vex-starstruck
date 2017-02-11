/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * This file contains the main drive train program.
 *
 * If the MOTOR_DEBUG constant is defined, the regular controls are disabled
 * and replaced by the debug controls.
 *
 * Controls:
 * -Left joystick Y:  Move left DT motors forward/backward.
 * -Right joystick Y: Move right DT motors forward/backward.
 * -Button 5U:        Move lift up.
 * -Button 5D:        Move lift down.
 *
 * Debug controls:
 * -Button 7U: Drive right back.
 * -Button 7D: Drive right front.
 * -Button 7L: Drive left front.
 * -Button 7R: Drive left back.
 * -Button 8U: Lift top left.
 * -Button 8D: Lift bottom right.
 * -Button 8L: Lift bottom left.
 * -Button 8R: Lift top right.
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
 * -static int joystick(int value)
 * 	-Pass in LJX, LJY, RJX, or RJY as parameters.
 *	-Processes the joystick value, doing any necessary calculations on it.
 *
 * Dependencies: lib.h.
 */

#include "lib.h"

#define LJX (vexRT[Ch4])
#define LJY (vexRT[Ch3])
#define RJX (vexRT[Ch1])
#define RJY (vexRT[Ch2])

#define J_MIN      10
#define LIFT_SPEED 127

static int
joystick(int value);

task
usercontrol()
{
	while (true)
	{
#ifndef MOTOR_DEBUG
		// drive train
		setLeftDT(joystick(LJY));
		setRightDT(joystick(RJY));
		// lift
		setLift(vexRT[Btn5U] ? LIFT_SPEED
			: vexRT[Btn5D] ? -LIFT_SPEED : 0);
#else // MOTOR_DEBUG
		debug(DRIVE_RB, Btn7U);
		debug(DRIVE_RF, Btn7D);
		debug(DRIVE_LF, Btn7L);
		debug(DRIVE_LB, Btn7R);
		debug(LIFT_TL, Btn8U);
		debug(LIFT_BR, Btn8D);
		debug(LIFT_BL, Btn8L);
		debug(LIFT_TR, Btn8R);
#endif // MOTOR_DEBUG
	}
}

int
joystick(int value)
{
	return fabs(value) >= J_MIN ? value : 0;
}
