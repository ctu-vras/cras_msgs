# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Czech Technical University in Prague

# Single stamped electric current measurement.

std_msgs/Header header  # stamp is the time the current was measured.
                        # frame_id is the location of the current measurement (does not need to be a TF frame).
ElectricCurrentMeasurement measurement  # The measured current.
