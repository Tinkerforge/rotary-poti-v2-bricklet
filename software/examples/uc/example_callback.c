// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "bindings/hal_common.h"
#include "bindings/bricklet_rotary_poti_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Rotary Poti Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


// Callback function for position callback
static void position_handler(TF_RotaryPotiV2 *device, int16_t position, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Position: %I16d °\n", position);
}

static TF_RotaryPotiV2 rp;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_rotary_poti_v2_create(&rp, UID, hal), "create device object");

	// Register position callback to function position_handler
	tf_rotary_poti_v2_register_position_callback(&rp,
	                                             position_handler,
	                                             NULL);

	// Set period for position callback to 0.25s (250ms) without a threshold
	tf_rotary_poti_v2_set_position_callback_configuration(&rp, 250, false, 'x', 0, 0);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
