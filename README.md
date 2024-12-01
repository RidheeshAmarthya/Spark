# Neural Network Implementation with GLSL Integration

## Overview

This project implements a custom neural network from scratch, with a focus on integrating GLSL (OpenGL Shading Language) for enhanced performance. It combines traditional CPU-based neural network computations with GPU-accelerated processing using GLSL shaders.

## Key Features

- **Custom Neural Network Layers**: Fully connected layers with forward and backward propagation.
- **Activation Functions**: ReLU, Softmax, and Sigmoid implementations.
- **Loss Functions**: Categorical Cross-Entropy for multi-class classification.
- **Optimizers**: SGD, Adam, RMSprop, and Adagrad.
- **GLSL Integration**: Utilizes GLSL shaders for parallel processing of neural network operations.

## GLSL Integration Highlights

### Vertex Shader Example

```glsl
#version 330 core

layout (location = 0) in vec4 position;
uniform mat4 pr_matrix;

void main()
{
    gl_Position = pr_matrix * position;
}
```

This vertex shader demonstrates how we transform input vertices using a projection matrix, crucial for rendering our neural network's output or visualizations.

### Fragment Shader Example

```glsl
#version 330 core

layout (location = 0) out vec4 color;
uniform vec4 colour;

void main()
{
    color = colour;
}
```

The fragment shader showcases how we can apply colors to our rendered output, which can be used to visualize neural network activations or results.

## Performance Optimizations

- **GPU Acceleration**: Leverages GLSL shaders for parallel processing of matrix operations.
- **Batch Processing**: Implements batch normalization and processing for improved training efficiency.
- **Optimized Math Operations**: Utilizes GLSL's built-in functions for fast mathematical computations.

## Future Developments

- Implement convolutional layers using GLSL for image processing tasks.
- Develop custom GLSL shaders for specific neural network architectures.
- Integrate real-time visualization of neural network training using OpenGL.

## Getting Started

1. Ensure you have OpenGL and GLSL support on your system.
2. Clone the repository and navigate to the project directory.
3. Compile the main file along with the neural network and GLSL shader files.
4. Run the executable to start training or using the neural network.

## Requirements

- OpenGL 3.3+
- GLSL 330+
- Python 3.x (for CPU-based operations)
- NumPy, Matplotlib (for data processing and visualization)
