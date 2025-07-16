# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Czech Technical University in Prague
 
# Single electric current measurement.
 
ElectricCurrent data  # Current value.
float64 variance  # Variance of the measurement (in Amperes^2). If not known or relevant, use 0.
builtin_interfaces/Duration sample_duration  # Duration of the measurement. If not known or relevant, use 0.
