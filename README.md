This is a simple C machine learning program that trains a single neuron how to correctly perform the AND logical operation using 2 input parameters; x1 and x2.

Example:
In order for the AND logical operation to return 1 ( true ) both input parameters must be 1 ( true ), this is done by training the neuron by adjusting its weights to value both parameters equally;
and its bias is shifted negatively with each training epoch.

For the neuron to return 1 on activation, the sum weighted sum of both parameters and its bias must be >= 0.0f (greater or equal to 0).
