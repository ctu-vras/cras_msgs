# Heartbeat messages can be sent by sensor drivers to allow easy diagnostics of publishing rate without the need to
# subscribe their possibly very large sensor messages.
# The following naming convention should be used. If the sensor topic is TOPIC, the corresponding heartbeat messages
# should be published to TOPIC/heartbeat . If this convention is followed, diagnostic tools can automatically assign
# the heartbeats to the correct base topics.
 
Header header  # Header of a (possibly much larger) message to which the heartbeat belongs