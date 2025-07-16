# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Czech Technical University in Prague

# Single power measurement.

std_msgs/Header header  # stamp is the time the power was measured.
                        # frame_id is the location of the power measurement (does not need to be a TF frame).
PowerMeasurement measurement  # The measured power.
