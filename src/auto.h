/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * Header for the autonomous program.
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
 * -void pre_auton()
 *
 * -void moveLift(bool dir)
 *     -Moves the lift completely up(true) or down(false).
 *     -If you don't want to remember that bit, just use the LIFT_UP and
 *      LIFT_DOWN constants.
 *     -What defines "fully raised/lowered" is the LIFT_WAIT constant.
 * -void moveDT(bool dir)
 *     -Moves the robot all the way forwards(true) backwards(false) up to the
 *      fence.
 *     -If you don't want to remember that bit, just use the DRIVE_FORWARD
 *      and DRIVE_BACKWARD constants.
 *     -What defines "up to the fence" is the DRIVE_WAIT constant.
 *
 * Dependencies: None.
 */

#ifndef AUTO_H
#define AUTO_H

#define LIFT_WAIT      750
#define LIFT_UP        true
#define LIFT_DOWN      false
#define DRIVE_WAIT     1735
#define DRIVE_FORWARD  true
#define DRIVE_BACKWARD false

void
moveLift(bool dir);

void
moveDT(bool dir);

#endif // AUTO_H
