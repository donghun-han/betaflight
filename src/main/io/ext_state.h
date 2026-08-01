/*
 * Get drone state from external sources (Jetson / GPS) and convert it to BTFL NED frame convention
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "common/maths.h"

typedef enum {
    EXT_STATE_GPS = 0,
} extStateSource_e;

typedef struct extState_s {
    uint32_t time_us;

    extStateSource_e source;
    fp_vector_t pos;
    fp_vector_t vel;
    fp_quaternion_t quat;

    bool is_new;
    bool is_vel_valid;
    bool is_quat_valid;
} extState_t;

extern extState_t extState;

void setExtState(const extState_t* newExtState);
