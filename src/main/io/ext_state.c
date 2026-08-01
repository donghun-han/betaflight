#include "common/time.h"

#include "io/ext_state.h"

#ifdef USE_EXT_STATE

extState_t extState;

void setExtState(const extState_t* newExtState) {
    if (cmpTimeUs(newExtState->time_us, extState.time_us) > 0) {
        extState = *newExtState;
        extState.is_new = true;
    }
}

#endif // USE_EXT_STATE