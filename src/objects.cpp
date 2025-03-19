#include "objects.h"
#include <cmath> // For physics calculations

namespace objects {

    // ======================================================================== //
    // =============================== Constructors =========================== //
    // ======================================================================== //
    Circle::Circle(float x, float y, float radius, float mass, bool is_static, float restitution) 
    : x(x), y(y), radius(radius), vx(0.0f), vy(0.0f), mass(mass), restitution(restitution), is_static(is_static), fx(0.0f), fy(0.0f) {}

    // ======================================================================== //
    // ================================== Getters ============================= //
    // ======================================================================== //
    float Circle::getX() const { return x;}
    float Circle::getY() const { return y;}
    float Circle::getRadius() const { return radius;}
    float Circle::getVelocityX() const { return vx;}
    float Circle::getVelocityY() const { return vy;}
    float Circle::getMass() const { return mass;}
    bool Circle::isStatic() const { return is_static;}
    float Circle::getRestitution() const { return restitution;}

    // ======================================================================== //
    // ================================== Setters ============================= //
    // ======================================================================== //
    void Circle::setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }
    void Circle::setVelocity(float newVx, float newVy) {
        vx = newVx;
        vy = newVy;
    }
    void Circle::setForce(float newFx, float newFy) {
        fx = newFx;
        fy = newFy;
    }
    void Circle::applyForce(float forceX, float forceY) {
        if (!is_static) {
            fx += forceX;
            fy += forceY;
        }
    }

    // ======================================================================== //
    // ============================== Update Functions ======================== //
    // ======================================================================== //
    void Circle::update(float deltaTime) {
        // calculate accelerations due to forces
        float ax = fx / mass;
        float ay = fy / mass;

        // Update velocities
        vx += ax * deltaTime;
        vy += ay * deltaTime;

        // Update positions
        x += vx * deltaTime;
        y += vy * deltaTime;

    }


} // Namespace objects