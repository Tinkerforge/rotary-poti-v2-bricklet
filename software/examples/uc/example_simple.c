// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_rotary_poti_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_RotaryPotiV2 rp;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_rotary_poti_v2_create(&rp, NULL, hal), "create device object");

	// Get current position
	int16_t position;
	check(tf_rotary_poti_v2_get_position(&rp, &position), "get position");

	tf_hal_printf("Position: %I16d °\n", position);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
