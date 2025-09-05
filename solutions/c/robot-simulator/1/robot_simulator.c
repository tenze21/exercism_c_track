#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_position_t initial_position= {x, y};
    robot_direction_t initial_direction= direction;
    robot_status_t initial_status={initial_direction, initial_position};
    return initial_status;
}

void robot_move(robot_status_t *robot, const char *commands){
    robot_direction_t current_direction= robot->direction;
    while(*commands){
        switch (*commands)
        {
        case 'R':
            current_direction = current_direction==DIRECTION_WEST? DIRECTION_NORTH : current_direction + 1;
            break;
        case 'L':
            current_direction= current_direction == DIRECTION_NORTH? DIRECTION_MAX - 1 : current_direction - 1;
            break;
        case 'A':
            if(current_direction == DIRECTION_NORTH) robot->position.y++;
            else if(current_direction == DIRECTION_EAST) robot->position.x++;
            else if(current_direction == DIRECTION_SOUTH) robot->position.y--;
            else robot->position.x--;
            break;
        default:
            break;
        }
        commands++;
    }
    robot->direction= current_direction;
}

// void main(){
//     robot_status_t actual = { DIRECTION_EAST, { 0, 0 } };
//     robot_move(&actual, "R");
// }