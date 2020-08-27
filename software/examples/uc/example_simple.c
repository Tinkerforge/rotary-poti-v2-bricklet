#include "bindings/hal_common.h"
#include "bindings/bricklet_rotary_poti_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Rotary Poti Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


static TF_RotaryPotiV2 rp;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_rotary_poti_v2_create(&rp, UID, hal), "create device object");

	// Get current position
	int16_t position;
	check(tf_rotary_poti_v2_get_position(&rp, &position), "get position");

	tf_hal_printf("Position: %d °\n", position);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
