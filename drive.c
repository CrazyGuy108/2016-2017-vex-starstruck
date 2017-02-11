/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * This is the implementation file for drive.h.
 * Look there for more info.
 *
 * Also contains the main drive train program.
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
 * Dependencies: drive.h, lib.h.
 */

#include "drive.h"
#include "lib.h"

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
