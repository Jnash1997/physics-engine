# Basic Physics Engine

## Overview

A light weight physics engine implemented in C++, designed for educational purposes and portfolio demonstration. The engine features a custom vector mathematics library and supports basic circular object physics including collision detection and response. This project combines fundamental physics principles with C++ to create an extensible foundation for physics-based simulations.

## Development Approach

Some sections of the source code for this project contain extensive inline documentation, more than would be seen typically in production code. This is because one of the primary goals of this project is a personal learning exercise for C++ concepts and syntax. These extensive inline comments therefore serve the purpose of documenting my learning process. If this then also aids in the learning of other developers examining the project, that is an added bonus.

## Features

- Custom template-based vector mathematics library with support for varying dimension sizes
- Vector operations including addition, subration, multiplication, dot product, cross product, and more
- Circle-based physics objects with customisable properties
- Velocity and force-based movement
- Mass and restitution handling
- Static and dynamic object support
- Real-time physics calculations
  
## Project Structure

```text
Basic_Physics_Engine
├── .vscode/
│  ├── c_cpp_properties.json
│  └── tasks.json
├── include/
│   ├── objects.h
│   └── vector.h
├── src/
│   ├── main.cpp
│   └── objects.cpp
├── tests/
├── main.exe
├── makefile
└── readme.md
```

## Installation

### Prerequisites

- C++ compilier (g++ recommended)
- Make build system

### Building the project

1. Clone the repository
2. Navigate to the project's root directory
3. Run `make` to build the project
4. The executible will be created in the project root

The makefile includes Windows=specific commands for compatability.

## Usuage

Here is a basic example of creating and using a physics object:

```cpp
#include <objects.h>
#include <vector.h>
#include <iostream>

int main() {
    // Create a 2D vector for position (x=0, y=1.5)
    vector::Vector<float, 2> position(0.0f, 1.5f);
    
    // Create a circle with position, radius 1.5, mass 10.3, dynamic state, and restitution 7.5
    objects::Circle circle(position, 1.5f, 10.3f, false, 7.5f);
    
    // Apply a force using the vector class
    vector::Vector<float, 2> force(5.0f, 3.0f);
    circle.applyForce(force);
    
    // Update physics (with 16ms timestep)
    circle.update(0.016f);
    
    // Get the position after update
    vector::Vector<float, 2> newPosition = circle.getPosition();
    std::cout << "New position: (" << newPosition[0] << ", " << newPosition[1] << ")" << std::endl;
    
    return 0;
}
```

## Technical Details

### Vector Class

The `vector` template class proivides a flexible mathematics library with:

- Template support for different numeric types and dimensions
- Multiple constructor options including default, variadic and copy constructors
- Overloaded operators for intuitive vector arithmetic
- Standard vector operations including magnitude, dot and cross products, angle between 2 vectors

### Circle Class

The `Circle` class represents a physical 2D circle object with properties including:

- Position as a 2D vector
- Velocity as a 2D vector
- Mass
- Radius
- Restitution coefficient
- Static/Dynamic state

### Physics Implementation

At the current state, the engine uses basic Newtonian physics:

- Force accumulation
- Velocity-based movement
- Simple collision detection

## Roadmap and Future Development

The project development is planned in several phases:

### Phase 1: Core Physics Engine (Current)

- [x] Basic circle physics implementation
- [x] Velocity and force-based movement
- [x] Simple collision detection and response
  - [x] Circle to Circle collision detection
  - [ ] Optimize spatial partitioning for collision detection
- [x] Create vector class with mathematical operations
  - [x] Template support for different dimensions and data types
  - [x] Overload standard operators for basic arithmetic
  - [x] Add advanced vector operations (dot product, cross product)
  - [ ] Vector normalisation and projection functions
- [x] Implement Vector Control
  - [x] Integration with circle class
  - [x] Vector-based force application
  - [ ] Vector-based impulse control
- [ ] Complex polygon shapes support
- [ ] Advanced physics features
  - [ ] Friction
  - [ ] Air resistance
  - [ ] Gravity
- [ ] Constraint-based joints and connections

### Phase 2: Python GUI Integration (Planned)

- [ ] Python wrapper for the C++ engine
- [ ] Real-time visualization of physics objects
- [ ] Interactive object creation and manipulation
- [ ] Physics parameter adjustment through UI
- [ ] Scene saving and loading capabilities
- [ ] Real-time physics property monitoring

### Phase 3: To Be Defined

## Feedback

This project is currently in development. Suggestions and feedback are welcome.
