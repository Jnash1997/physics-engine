#ifndef VECTOR_H
#define VECTOR_H

// Includes
#include <cmath> // For math functions

namespace vector{

    /* Create vector class with variable dimension sizing
    Template will cause the compiler to create the class as necessary
    for different values of Dimension, allowing for multiple vectors 
    of different dimensions to be created with this single class.
    This is also why the implementation is defined in the header file:
    the compilier will need to create a new class each time a new 
    instance of the class is created with different template parameters.
    Therefore the compiler needs to see the full template and not just what is
    in the implementation file, other wise linker errors will occur.Vector
    T = type template parameter, allowing for different data types
    Dimension = non-type template parameter.
    Vector<int, 2> will create a 2D vector of integers
    Vector<std::string, 3> will create a 3D vector of strings etc.*/
    template<typename T, int Dimension>
    class Vector {
        // private parameters that will not be changed
        private:
            T components[Dimension]; // Define array to store the components of the vector

        // public accessible parameters
        public:
            // ======================================================================== //
            // =============================== Constructors =========================== //
            // ======================================================================== //
            /*Note that the Vector function is defined thrice. As all 3
            instances of this function require different inputs, the 
            compiler is still able to differentiate between each of 
            these functions. This is called overloading the function.*/

            /* Allows for Vector command with no input variables to create a 
            default vector if zeros*/
            Vector(){
                for(int i = 0; i < Dimension; i++){
                    components[i] = T(0);
                };
            };

            /* Allows for Vector command to parse Dimension numeber of type T 
            input variables to create the vector of desired length.
            Const prevents the function from altering the values of the input 
            array during the execution*/
            explicit Vector(const T values[Dimension]){
                for(int i = 0; i < Dimension; i++){
                    components[i] = values[i];
                };
            };
            
            /*Allow Vector command to create a new vector by copying all values 
            from an existing vector of the same type and dimension, without 
            altering the original.*/
            Vector(const Vector<T, Dimension>& other){
                for(int i = 0; i < Dimension; i++){
                    components[i] = other[i];
                }
            };
            
            // ======================================================================== //
            // ================================ Operators ============================= //
            // ======================================================================== //

            /* Create a definition of the [] operator for our vector class.
            i.e. if we have an int vector vec, we could store the 1st value of that
            vector by running: int x = vec[0];
            Similarly we can alter the values of vec by running vec[0] = int(10);
            This is because we used the & operator, which tells the operator that we 
            are calling a reference to the actual value of the return value.
            In other words, [] will return the address where the variable is stored
            opposed to making a new parameter with the same value.*/
            T& operator[](int index){
                return components[index];
            }

            /* As the above allows for direct editing of a vector, it cannot be used 
            when a vector is defined as a const. This is why we need the following 
            version of the operator definintion to allow for pulling a specific index
            from a const vector. The first const allows for viewing of the reference
            but prevents editing (i.e protects the vector element). The second const 
            tells the compiler that the method of this operator will not edit the vector
            that the operator is called on (i.e. protects the vector as a whole).*/
            const T& operator[](int index) const {
                return components[index];
            }

            /* Vector addition operators
            Will return a Vector with the same dimensions and internal data type of the
            objects used in the addition.  
            `const Vector<T, Dimension>& other` allows + to take in a reference (&) to 
            a second vector on the right hand side of the operator while ensuring that 
            vector is not edited (const).
            The const before the function implementation (within the {}) ensures the 
            initial vector cannot itself be editted*/

            Vector<T, Dimension> operator+=(const Vector<T, Dimension>& other){
                for(int i=0; i < Dimension; i++){
                    components[i] += other[i];
                }
                return *this;
            }

            Vector<T, Dimension> operator+(const Vector<T, Dimension>& other) const{
                // Copy of the object being acted upon using the above defined constructor
                Vector<T, Dimension> result(*this);
                // add input vector to the copied version of the initial vector
                result += other;
                return result;
            }

            // Vector subtraction

            Vector<T, Dimension> operator-=(const Vector<T, Dimension>& other){
                for(int i=0; i < Dimension; i++){
                    components[i] -= other[i];
                }
                return *this;
            }

            Vector<T, Dimension> operator-(const Vector<T, Dimension>& other) const{
                Vector<T, Dimension> result(*this);
                result -= other;
                return result;
            }

            /* Multiplication by scalar
            Note that due to the way c++ works this will only allow for 
            Vector * Scalar and will not allow Scalar * Vector !!!
            This is because the operator keyword assumes that the left side opperand is 
            an instance of the class. We get around this by overloading the * operator 
            again outside the class definition. We can then call this function and 
            reverse the order manually to prevent duplicate code*/
            Vector<T, Dimension> operator*(T scalar) const {
                Vector<T, Dimension> result;
                for(int i=0; i< Dimension; i++){
                    result[i] = components[i] * scalar;
                }
                return result;
            }

           

            // ======================================================================== //
            // ========================== Vector Math Functions ======================= //
            // ======================================================================== //

            // Magnitude
            
            T magnitude() const {
                T result = 0;
                for(int i=0; i < Dimension; i++){
                    result += components[i] * components[i];
                }

                result = std::sqrt(result);
                return result;
            }
            
            // Angle between 2 Vectors
            double angle(const Vector<T, Dimension>& other) const {
                double result;

                /* this is the pointer to the current instance of the class 
                the arrow operator (->) is used for calling a method on the object a 
                pointer is referring to (opposed to the dot (.) operator)*/
                result = std::acos((this->dot(other)) / (this->magnitude() * other.magnitude()));

                return result;
            }

            // Dot product
            T dot(const Vector<T, Dimension>& other) const {
                T result = 0;
                for(int i=0; i < Dimension; i++){
                    result += components[i] * other[i];
                }
                return result;
            }

            // Cross product
            Vector<T, Dimension> cross(const Vector<T, Dimension>& other) const {
                /* static_assert creates a compile time error with the given message when the 
                condition specified is not met static_assert is evaluated at compilation and 
                not during runtime, saving on runtime resources.*/
                static_assert(Dimension == 3, "Cross product is only defined for 3D vectors!");
                // Calculation of elements
                Vector<T, 3> result;
                result[0] = components[1] * other[2] - components[2] * other[1];
                result[1] = components[2] * other[0] - components[0] * other[2];
                result[2] = components[0] * other[1] - components[1] * other[0];

                return result;
            }

    };

    // ================================================================================ //
    // =========================== Non-member Utility Functions ======================= //
    // ================================================================================ //

    // Multiplication by scalar (reversed)
    template<typename T, int Dimension>
    Vector<T, Dimension> operator*(T scalar, const Vector<T, Dimension>& vec) {
        return vec * scalar;
    }



} // namespace vector
#endif