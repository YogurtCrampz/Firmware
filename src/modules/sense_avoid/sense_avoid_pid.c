#include "sense_avoid.h"

/* PID controller for error */
int sense_avoid_PID(int goal_dist, int cur_dist) {
    /* https://tutorial.cytron.io/2012/06/22/pid-for-embedded-design/ 
    https://www.embedded.com/design/prototyping-and-development/4211211/PID-without-a-PhD */

    int pid_out = 10;
    return pid_out;
}