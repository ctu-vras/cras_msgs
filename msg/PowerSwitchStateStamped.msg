# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Czech Technical University in Prague

# State of a power switch (a relay, a transistor, FET...).

Header header  # stamp is the time the power switch state was measured.
               # frame_id is the location of the power switch (does not need to be TF frame).
PowerSwitchState state  # State of the power switch light.
