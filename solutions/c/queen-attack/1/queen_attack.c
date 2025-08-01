#include <stdlib.h>
#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if((queen_1.row == queen_2.row) && (queen_1.column == queen_2.column))/*both queens are on the same position*/
        return INVALID_POSITION;
    else if(queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7)/*if any of the queens position is not on the board*/
        return INVALID_POSITION;
    else if((queen_1.row == queen_2.row) || (queen_1.column == queen_2.column))/*if the queens either share a row or a column*/
        return CAN_ATTACK;
    else if(abs(queen_2.row - queen_1.row) == abs(queen_2.column - queen_1.column)) /*if the queens are on the same diagonal(using absolute diagonals)*/
        return CAN_ATTACK;
    else 
        return CAN_NOT_ATTACK;
}