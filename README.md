# Basic Physics Engine

## Overview

A light weight 2D physics engine implemented in C++, designed for educational purposes and portfolio demonstration. The engine currently supports basic circular object physics including collision detection and response.

## Features

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
├── build/
│  ├── main.o
│  └── objects.o
├── docs/
│   ├── api/
│   ├── examples/
│   └── latex/
├── include/
│   └── objects.h
├── lib/
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
3. Run make to build the project
4. The executible will be created in the project root

## Usuage

Here is a basic example of creating and using a physics object:

```cpp
#include <objects.h>

int main() {
    // Create a circle with position (0,0), radius 10 and mass 1
    objects::Circle circle(0.0f, 0.0f, 10.0f, 1.0f);
    // Apply a force
    circle.applyForce(1.0f, 0.0f);
    
    // Update physics (with 16ms timestep)
    circle.update(0.016f);
    
    return 0;
}
```

## Technical Details

### Circle Class

The `Circle` class represents a physical 2D circle object with properties including:

- Position (x,y)
- Velocity components
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
- [ ] Implement Vector Control
- [ ] Complex polygon shapes support
- [ ] Advanced physics features (friction, air resistance)
- [ ] Constraint-based joints and connections

### Phase 2: Python GUI Integration (Planned)

- [ ] Python wrapper for the C++ engine
- [ ] Real-time visualization of physics objects
- [ ] Interactive object creation and manipulation
- [ ] Physics parameter adjustment through UI
- [ ] Scene saving and loading capabilities
- [ ] Real-time physics property monitoring

### Phase 3: Extended Features

- [ ] Particle systems
- [ ] Soft body physics
- [ ] Performance optimisation
- [ ] Multiple physics world support

## Feedback

This project is currently in development.Suggestions and feedback are welcome.
