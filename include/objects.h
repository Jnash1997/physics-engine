#ifndef OBJECT_H // Inclusion guard
#define OBJECT_H 

#include <vector.h>

namespace objects {

    class Circle {
    private:
        vector::Vector<float, 2> position;  // position vector
        float radius;                       // radius of the circle
        float mass;                         // mass of the circle
        bool is_static;                     // static flag (true if immovable)
        float restitution;                  // elasticity
        vector::Vector<float, 2> velocity;  // velocity vector
        vector::Vector<float, 2>  force;    // accumulated forces vector

    public:
        // ======================================================================== //
        // =============================== Constructors =========================== //
        // ======================================================================== //
        Circle(vector::Vector<float, 2> pos , float radius, float mass, bool is_static = false, float restitution = 1.0f);

        // ======================================================================== //
        // ================================== Getters ============================= //
        // ======================================================================== //
        vector::Vector<float, 2> getPosition() const;
        float getRadius() const;
        vector::Vector<float, 2> getVelocity() const;
        float getMass() const;
        bool isStatic() const;
        float getRestitution() const;

        // ======================================================================== //
        // ================================== Setters ============================= //
        // ======================================================================== //
        void setPosition(float newX, float newY);
        void setPosition(const vector::Vector<float, 2>& newPos);
        void setVelocity(float newVx, float newVy);
        void setVelocity(const vector::Vector<float, 2>& newVel);
        void setForce(float newFx, float newFy);
        void setForce(const vector::Vector<float, 2>& newForce);
        void applyForce(float forceX, float forceY);    // To apply additional forces
        void applyForce(const vector::Vector<float, 2>& appliedForce);    

        // Update position based on velocity and forces
        void update(float deltaTime);

    };

} // namespace objects

#endif
