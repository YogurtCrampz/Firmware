/**
 * @file sense_avoid_example.c
 * Minimal application example for PX4 autopilot
 *
 * @author Example User <mail@example.com>
 */

/* Usage Notes: Can start your application as a background process/task by typing the following in the nsh shell:
                        sense_avoid &
*/



#include "sense_avoid.h"





/*The main function must be named <module_name>_main and exported from the module as shown.*/
__EXPORT int sense_avoid_main(int argc, char *argv[]);


int sense_avoid_main(int argc, char *argv[])
{
    /* subscribe to topics */
    int sensor_sub_fd = orb_subscribe(ORB_ID(sensor_combined));
    //int dist_sensor_sub_fd = orb_subscribe(ORB_ID(distance_sensor));

    /* publish topics */
        /* advertise attitude topic */
            /* initialize the struct of the topic to be published and advertise the topic */
    struct vehicle_attitude_s att;
    memset(&att, 0, sizeof(att));
    orb_advert_t att_pub_fd = orb_advertise(ORB_ID(vehicle_attitude), &att);

        /* publish vehicle commands */
    /*struct vehicle_command_s cmd;
    memset(&cmd, 0, sizeof(cmd));
    orb_advert_t comm_pub_fd = orb_advertise(ORB_ID(vehicle_command), &cmd);*/

    /*PX4_INFO is the equivalent of printf for the PX4 shell (included from px4_log.h). 
    There are different log levels: PX4_INFO, PX4_WARN, PX4_ERR, PX4_DEBUG. Warnings and 
    errors are additionally added to the ULog and shown on Flight Review.*/
    PX4_INFO("Hello Sky!");

    /*The sensor_sub_fd is a topic handle and can be used to very efficiently perform a 
    blocking wait for new data. The current thread goes to sleep and is woken up automatically 
    by the scheduler once new data is available, not consuming any CPU cycles while waiting. 
    To do this, we use the poll() POSIX system call.*/

    /* one could wait for multiple topics with this technique, just using one here */
    px4_pollfd_struct_t fds[] = {
        { .fd = sensor_sub_fd,   .events = POLLIN },
        /* there could be more file descriptors here, in the form like:
		 * { .fd = other_sub_fd,   .events = POLLIN },
		 */
    };

    int error_counter = 0;

    for (int i = 0; i < 5; i++) {
        /* wait for sensor update of 1 file descriptor for 1000 ms (1 second) */
        int poll_ret = px4_poll(fds, 1, 1000);
        
        /* handle the poll result */
        if (poll_ret == 0) {
            PX4_ERR("Got no data within a second");
        } else if (poll_ret < 0) {
            /* this is seriously bad - should be an emergency */
			if (error_counter < 10 || error_counter % 50 == 0) {
				/* use a counter to prevent flooding (and slowing us down) */
				PX4_ERR("ERROR return value from poll(): %d", poll_ret);
			}

			error_counter++;
        } else {
            if (fds[0].revents & POLLIN) {
                /* obtained data for the first file descriptor */
                struct sensor_combined_s raw;
                /* copy sensors raw data into local buffer */
                orb_copy(ORB_ID(sensor_combined), sensor_sub_fd, &raw);
                PX4_INFO("Accelerometer:\t%8.4f\t%8.4f\t%8.4f",
                            (double)raw.accelerometer_m_s2[0],
                            (double)raw.accelerometer_m_s2[1],
                            (double)raw.accelerometer_m_s2[2]);

                /* In the main loop, publish the information whenever its ready */

                /* set att and publish this information for other apps
                 the following does not have any meaning, it's just an example
                */
                att.q[0] = raw.accelerometer_m_s2[0];
                att.q[1] = raw.accelerometer_m_s2[1];
                att.q[2] = raw.accelerometer_m_s2[2];

                orb_publish(ORB_ID(vehicle_attitude), att_pub_fd, &att);
            }
            /* there could be more file descriptors here, in the form like:
             * if (fds[1..n].revents & POLLIN) {}
             */
        }
        
    }

    return OK;
}


