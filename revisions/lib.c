/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * This is the implementation file for lib.h.
 * Look there for more info.
 *
 * Dependencies: lib.h.
 */

#include "lib.h"

void
setLeftDT(int speed)
{
	motor[DRIVE_LF]  = speed;
	motor[DRIVE_LB]  = speed;
}

void
setRightDT(int speed)
{
	motor[DRIVE_RF] = speed;
	motor[DRIVE_RB] = speed;
}

void
setBothDT(int speed)
{
	setLeftDT(speed);
	setRightDT(speed);
}

void
setLift(int speed)
{
	motor[LIFT_TL] = speed;
	motor[LIFT_BR] = speed;
	motor[LIFT_BL] = speed;
	motor[LIFT_TR] = speed;
}

void
debug(int port, int button)
{
	motor[port] = vexRT[button] ? 127 : 0;
}
