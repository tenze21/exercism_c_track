#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y){/*define the robot with it's initial position and direction*/
    robot_position_t initial_position= {x, y};
    robot_direction_t initial_direction= direction;
    robot_status_t initial_status={initial_direction, initial_position};
    // robot_status_t status={.direction= direction, .position={.x=x, .y=y}};
    return initial_status;
}

void robot_move(robot_status_t *robot, const char *commands){/*Change the robots position and direction based on the command sequence.*/
    static int incx[]={0, 1, 0, -1};
    static int incy[]={1, 0, -1, 0};
    while(*commands){
        switch (*commands)
        {
        case 'R':
            robot->direction= (robot->direction + 1) % DIRECTION_MAX;
            break;
        case 'L':
            robot->direction=(robot->direction + 3) % DIRECTION_MAX;
            break;
        case 'A':
            robot->position.x+=incx[robot->direction];
            robot->position.y+=incy[robot->direction];
            break;
        default:
            break;
        }
        commands++;
    }
}