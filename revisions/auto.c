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
 * Symbolic constants:
 * -LIFT_WAIT:      The amount of milliseconds to wait until the lift is fully
 *                  raised/lowered.
 * -LIFT_UP:        Signal to move the lift up.
 * -LIFT_DOWN:      Signal to move the lift down.
 * -DRIVE_WAIT:     The amount of milliseconds to wait until the robot has
 *                  driven all the way forwards/backwards up to the fence.
 * -DRIVE_FORWARD:  Signal to move the drive train forwards.
 * -DRIVE_BACKWARD: Signal to move the drive train backwards.
 *
 * Functions:
 * -static void moveLift(bool dir)
 *     -Moves the lift completely up(true) or down(false).
 *     -If you don't want to remember that bit, just use the LIFT_UP and
 *      LIFT_DOWN constants.
 *     -What defines "fully raised/lowered" is the LIFT_WAIT constant.
 * -static void moveDT(bool dir)
 *     -Moves the robot all the way forwards(true) backwards(false) up to the
 *      fence.
 *     -If you don't want to remember that bit, just use the DRIVE_FORWARD
 *      and DRIVE_BACKWARD constants.
 *     -What defines "up to the fence" is the DRIVE_WAIT constant.
 *
 * Dependencies: lib.h.
 */

#include "lib.h"

#define LIFT_WAIT      750
#define LIFT_UP        true
#define LIFT_DOWN      false
#define DRIVE_WAIT     1735
#define DRIVE_FORWARD  true
#define DRIVE_BACKWARD false

static void
moveLift(bool dir);

static void
moveDT(bool dir);

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
