#include "objects.h"
#include <cmath> // For physics calculations
#include <vector.h>

namespace objects {

    // ======================================================================== //
    // =============================== Constructors =========================== //
    // ======================================================================== //
    Circle::Circle(vector::Vector<float, 2> pos, float radius, float mass, bool is_static, float restitution) 
    : position(pos), radius(radius), mass(mass), is_static(is_static), restitution(restitution), velocity(), force() {}

    // ======================================================================== //
    // ================================== Getters ============================= //
    // ======================================================================== //
    vector::Vector<float, 2> Circle::getPosition() const { return position;}
    float Circle::getRadius() const { return radius;}
    vector::Vector<float, 2> Circle::getVelocity() const { return velocity;}
    float Circle::getMass() const { return mass;}
    bool Circle::isStatic() const { return is_static;}
    float Circle::getRestitution() const { return restitution;}

    // ======================================================================== //
    // ================================== Setters ============================= //
    // ======================================================================== //
    
    // Position Setters
    void Circle::setPosition(float newX, float newY) {
        position[0] = newX;
        position[1] = newY;
    }
    void Circle::setPosition(const vector::Vector<float, 2>& newPos){ position = newPos; }

    // Velocity Setters
    void Circle::setVelocity(float newVx, float newVy) {
        velocity[0] = newVx;
        velocity[1] = newVy;
    }
    void Circle::setVelocity(const vector::Vector<float, 2>& newVel){ velocity = newVel;}

    // Force Setters
    void Circle::setForce(float newFx, float newFy) {
        force[0] = newFx;
        force[1] = newFy;
    }
    void Circle::setForce(const vector::Vector<float, 2>& newForce){ force = newForce; }

    void Circle::applyForce(float forceX, float forceY) {
        if (!is_static) {
            force[0] += forceX;
            force[1] += forceY;
        }
    }
    void Circle::applyForce(const vector::Vector<float, 2>& appliedForce){ force += appliedForce; }; 

    // ======================================================================== //
    // ============================== Update Functions ======================== //
    // ======================================================================== //
    void Circle::update(float deltaTime) {
        // calculate accelerations due to forces
        vector::Vector<float, 2> acceleration;
        acceleration[0] = force[0] / mass;
        acceleration[1] = force[1] / mass;

        // Update velocities
        velocity[0] += acceleration[0] * deltaTime;
        velocity[1] += acceleration[1] * deltaTime;

        // Update positions
        position[0] += velocity[0] * deltaTime;
        position[1] += velocity[1] * deltaTime;

    }


} // Namespace objects