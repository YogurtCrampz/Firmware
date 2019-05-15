/****************************************************************************
 *
 *   Copyright (c) 2018 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#pragma once

//#include <px4_module.h>
//#include <px4_module_params.h>



#include <px4_log.h>
#include <poll.h>

//#include <px4_config.h>
//#include <px4_tasks.h>
#include <px4_posix.h> // needed for px4_pollfd_struct_t type
//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>
//#include <math.h>

//#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h> /* subscribing to sensor data */
#include <uORB/topics/distance_sensor.h> /* subscribing to distance sensor data */
#include <uORB/topics/vehicle_attitude.h> /* publishing attitude topic */
#include <uORB/topics/vehicle_command.h> /* publish velocity commands */
/* https://github.com/PX4/Firmware/blob/master/msg/vehicle_command.msg */
//#include <uORB/topics/vehicle_control_mode.h> /* publish flight mode */


//typedef char state;
enum state {
    NORMAL,
    STOPPING,
    RISING
};

/* Feedback Controller */
int sense_avoid_PID(int goal_dist, int cur_dist);

/* Plant */
int sense_avoid_plant(int ctrl_out);

/* External Controller State Machine */
enum state state_machine(enum state current_state, enum state next_state);
