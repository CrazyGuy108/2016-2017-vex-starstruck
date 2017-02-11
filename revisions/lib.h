/*
 * TAYLOR HANSEN, HAMZA LAWAI
 *
 * What goes here are library functions necessary in both the autonomous and
 * drive periods.
 *
 * Functions:
 * -void setLeftDT(int speed)
 * 	-Sets the left DT motors at the given speed.
 * -void setRightDT(int speed)
 * 	-Sets the right DT motors at the given speed.
 * -void setBothDT(int speed)
 * 	-Sets both the left and the right DT motors at the given speed.
 * -void setLift(int speed)
 * 	-Sets the lift motors at the given speed.
 * -void debug(int port, int button)
 * 	-If button is pressed, sets port to 127, else 0.
 * 	-Used for debugging motors and running tests.
 *
 * Dependencies: None.
 */

#ifndef LIB_H
#define LIB_H

void
setLeftDT(int speed);

void
setRightDT(int speed);

void
setBothDT(int speed);

void
setLift(int speed);

void
debug(int port, int button);

#endif // LIB_H
