#include "sense_avoid.h"

/* Takes value from PID and sends corresponding commands to commander */
int sense_avoid_plant(int ctrl_out) {
/*
uint16 VEHICLE_CMD_NAV_GUIDED_LIMITS = 90		# set limits for external control |timeout - maximum time 
(in seconds) that external controller will be allowed to control vehicle. 0 means no timeout| absolute 
altitude min (in meters, AMSL) - if vehicle moves below this alt, the command will be aborted and the mission 
will continue.  0 means no lower altitude limit| absolute altitude max (in meters)- if vehicle moves above this 
alt, the command will be aborted and the mission will continue.  0 means no upper altitude limit| horizontal 
move limit (in meters, AMSL) - if vehicle moves more than this distance from it's location at the moment the 
command was executed, the command will be aborted and the mission will continue. 0 means no horizontal altitude 
limit| Empty| Empty| Empty|.

uint16 VEHICLE_CMD_NAV_GUIDED_ENABLE = 92		# hand control over to an external controller |On / Off (> 0.5f on)| 
Empty| Empty| Empty| Empty| Empty| Empty|.

uint16 VEHICLE_CMD_CONDITION_CHANGE_ALT = 113		# Ascend/descend at rate.  Delay mission state machine until 
desired altitude reached. |Descent / Ascend rate (m/s)| Empty| Empty| Empty| Empty| Empty| Finish Altitude|.

uint16 VEHICLE_CMD_DO_SET_MODE = 176			# Set system mode. |Mode, as defined by ENUM MAV_MODE| Empty| 
Empty| Empty| Empty| Empty| Empty|

uint16 VEHICLE_CMD_DO_CHANGE_SPEED = 178		# Change speed and/or throttle set points. |Speed type (0=Airspeed, 
1=Ground Speed)| Speed  (m/s, -1 indicates no change)| Throttle  ( Percent, -1 indicates no change)| Empty| Empty| Empty| Empty|.

uint16 VEHICLE_CMD_DO_GUIDED_MASTER=221			# set id of master controller |System ID| Component ID| Empty| 
Empty| Empty| Empty| Empty|

uint16 VEHICLE_CMD_DO_GUIDED_LIMITS=222			# set limits for external control |timeout - maximum time (in seconds) 
that external controller will be allowed to control vehicle. 0 means no timeout| absolute altitude min (in meters, AMSL) 
- if vehicle moves below this alt, the command will be aborted and the mission will continue.  0 means no lower 
altitude limit| absolute altitude max (in meters)- if vehicle moves above this alt, the command will be aborted and 
the mission will continue.  0 means no upper altitude limit| horizontal move limit (in meters, AMSL) - if vehicle moves 
more than this distance from it's location at the moment the command was executed, the command will be aborted and 
the mission will continue. 0 means no horizontal altitude limit| Empty| Empty| Empty|.

*/
    int plant_out = 10;

    return plant_out;
}
