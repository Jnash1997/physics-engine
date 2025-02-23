#ifndef OBJECT_H // Inclusion guard
#define OBJECT_H 

namespace objects {

    class Circle {
    private:
        float x, y;             // x and y coordinates of the circle's center
        float radius;           // radius of the circle
        float vx, vy;           // x and y components of the circle's velocity
        float mass;             // mass of the circle
        float restitution;      // elasticity
        bool is_static;         // static flag (true if immovable)
        float fx, fy;           // x, y components of accumulated forces

    public:
        // Constructor function
        Circle(float x, float y, float radius, float mass, bool is_static = false, float restitution = 1.0f);

        // Getters
        float getX() const;
        float getY() const;
        float getRadius() const;
        float getVelocityX() const;
        float getVelocityY() const;
        float getMass() const;
        bool isStatic() const;
        float getRestitution() const;

        // Setters
        void setPosition(float newX, float newY);
        void setVelocity(float newVx, float newVy);
        void setForce(float newFx, float newFy);
        void applyForce(float forceX, float forceY);    // To apply additional forces

        // Update position based on velocity and forces
        void update(float deltaTime);

    };

} // namespace objects

#endif
