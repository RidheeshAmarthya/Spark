# Sparky Game Engine

## Overview

The Sparky Game Engine is a custom 2D game engine developed using C++ and OpenGL, designed as part of a YouTube tutorial series. This project focuses on creating a flexible and efficient rendering system that leverages modern graphics programming techniques, particularly through the use of GLSL (OpenGL Shading Language) for shader management.

## Screenshots
                            <img src="https://imgur.com/55k6JS2.png" alt="Spark Screenshot 1">
                            <img src="https://imgur.com/Q5YqEdv.png" alt="Spark Screenshot 2">

## Technical Highlights

### OpenGL and GLSL Integration
- **Shader Management**: The engine utilizes vertex and fragment shaders written in GLSL to control the rendering pipeline, allowing for dynamic graphics effects and efficient rendering.
- **Custom Shaders**: Implemented shaders include basic transformations and color manipulations, providing a foundation for more complex visual effects.

### Rendering Pipeline
- **Vertex Array Objects (VAOs)**: Used to encapsulate vertex buffer configurations, reducing the overhead of state changes during rendering.
- **Vertex Buffer Objects (VBOs)**: Efficiently manage vertex data in GPU memory, ensuring fast access during rendering.
- **Batch Rendering**: Implements a `BatchRenderer2D` class that groups multiple draw calls into a single call to minimize CPU overhead and improve performance.

### Math Utilities
- **Matrix Operations**: A custom mathematics library provides essential operations for matrix transformations, crucial for 2D graphics rendering.
- **Orthographic Projection**: Utilizes an orthographic projection matrix to maintain consistent scaling across different screen sizes.

### Dynamic Sprite Management
- **Sprite Creation**: Supports the creation of dynamic sprites with random colors and positions, demonstrating the engine's capability to handle multiple renderable objects efficiently.
- **Mouse Interaction**: Captures mouse position to create interactive elements within the game environment, allowing for dynamic lighting effects based on user input.

## Core Components

### Main File Breakdown
The main file serves as the entry point for the engine, initializing the window, shaders, and rendering components. Key sections include:

1. **Window Initialization**: Creates a window using the `Window` class.
2. **Shader Setup**: Loads and compiles shaders from specified file paths.
3. **Sprite Generation**: Dynamically generates a grid of colorful sprites to be rendered on the screen.
4. **Rendering Loop**: Continuously updates the window, processes input, and renders sprites until the window is closed.

### Example Shader Code

#### Vertex Shader (`basic.vert`)
```glsl
#version 330 core
layout (location = 0) in vec4 position;
uniform mat4 pr_matrix;

void main()
{
    gl_Position = pr_matrix * position;
}
```

#### Fragment Shader (`basic.frag`)
```glsl
#version 330 core
layout (location = 0) out vec4 color;
uniform vec4 colour;

void main()
{
    color = colour;
}
```

These shaders are fundamental for transforming vertex positions and applying colors to rendered objects.

## Future Development Plans
- **Advanced Rendering Techniques**: Explore additional rendering techniques such as lighting models, shadow mapping, and texture mapping.
- **Physics Integration**: Incorporate physics simulations for more realistic interactions within the game environment.
- **Scene Management**: Develop a scene graph system to manage complex scenes with multiple layers and objects efficiently.

## Getting Started

To run this project:

1. Ensure you have OpenGL development libraries installed on your system.
2. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/sparky-game-engine.git
   cd sparky-game-engine
   ```
3. Compile the project using your preferred C++ compiler with OpenGL support.
4. Execute the compiled binary to launch the engine and view the dynamic sprite rendering.

## Acknowledgements

This project is based on a YouTube tutorial series that provides insights into game engine development using C++ and OpenGL. 
