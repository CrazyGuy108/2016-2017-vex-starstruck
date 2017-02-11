/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * This is the implementation file for auto.h.
 * Look there for more info.
 *
 * Also contains the main autonomous program.
 *
 * Autonomous Procedure:
 *  1. Move the lift upwards.
 *  2. Drive forwards and knock down the stars on the fence.
 *  3. Drive backwards to give the robot some space.
 *  4. Move the lift back down.
 *
 * Dependencies: auto.h, lib.h.
 */

#include "auto.h"
#include "lib.h"

void
pre_auton()
{
}

task
autonomous()
{
	moveLift(LIFT_UP);
	moveDT(DRIVE_FORWARD);
	wait1Msec(500);
	moveDT(DRIVE_BACKWARD);
	moveLift(LIFT_DOWN);
	//moveDT(DRIVE_FORWARD);
}

void
moveLift(bool dir)
{
	setLift(dir ? 127 : -127);
	wait1Msec(LIFT_WAIT);
	setLift(0);
}

void
moveDT(bool dir)
{
	setBothDT(dir ? 127 : -63);
	wait1Msec(DRIVE_WAIT);
	setBothDT(0);
}
