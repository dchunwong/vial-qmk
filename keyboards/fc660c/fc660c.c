/*
Copyright 2017 Balz Guenat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "fc660c.h"

#ifdef ACTUATION_DEPTH_ADJUSTMENT
#include "actuation_point.h"
#endif

void matrix_init_kb(void) {
#ifdef ACTUATION_DEPTH_ADJUSTMENT
    adjust_actuation_point(ACTUATION_DEPTH_ADJUSTMENT);
#endif

	matrix_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        //Insert LED
        PORTB &= ~(1<<5);
        break;
    default: //  for any other layers, or the default layer
        //Insert LED
        PORTB |=  (1<<5);
    }
    return state;
}
