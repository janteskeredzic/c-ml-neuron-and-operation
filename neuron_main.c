#include <stdio.h>
#include <math.h>

typedef struct
{
	float weights[2];
	float bias;
} Neuron;

float training_inputs[4][2] =
{
	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 1, 1 }
};

int expected_outputs[4] = { 0, 0, 0, 1 };

float sigmoid(float x)
{
	return 1.0f / (1.0f + expf(-x));
}

int activation(float x)
{
	return x >= 0.0f ? 1 : 0;
}


int neuron_forward(Neuron* n, float inputs[2])
{
	float sum = n->bias;
	
	for(int i = 0; i < 2; ++i)
	{
		sum += inputs[i] * n->weights[i];
	}
	return activation(sum);
}



void neuron_train(Neuron* n, float inputs[2], int desired, float learning_rate)
{
	int currentOutput = neuron_forward(n, inputs);
	int error = desired - currentOutput;
	n->weights[0] = n->weights[0] + learning_rate * error * inputs[0];
	n->weights[1] = n->weights[1] + learning_rate * error * inputs[1];
	
	n->bias = n->bias + learning_rate * error;
}

int main(void)
{
	Neuron neuron =
	{
		.weights = { 0.5f, -0.3f},
		.bias = 0.2f
	};
	
	
	for(int epoch = 0; epoch < 20; ++epoch)
	{
		for(int i = 0; i < 4; ++i)
		{
			neuron_train(&neuron, training_inputs[i], expected_outputs[i], 0.1f);
		}
	}
	
	for(int i = 0; i < 4; ++i)
	{
		float output = neuron_forward(&neuron, training_inputs[i]);
		printf("Neuron output from data(%f, %f) for AND operation: %f\n", training_inputs[i][0], training_inputs[i][1], output);
	}
	printf("\nNeuron w1: %f w2: %f bias: %f \n", neuron.weights[0], neuron.weights[1], neuron.bias);
	
	return 0;
}