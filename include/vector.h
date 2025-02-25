#ifndef VECTOR_H
#define VECTOR_H

namespace vector{

    /* Create vector class with variable dimension sizing
    Template will cause the compiler to create the class as necessary
    for different values of Dimension, allowing for multiple vectors 
    of different dimensions to be created with this single class.
    In this case, Dimension is the tempate parameter.
    Vector<int, 2> will create a 2D vector of integers
    Vector<std::string, 3> will create a 3D vector of strings etc.*/
    template<typename T, int Dimension>
    class Vector {
        // private parameters that will not be changed
        private:
            T components[Dimension]; // Define array to store the components of the vector            

        // public accessible parameters
        public:
            // Constructors

            /* Allows for Vector command with no input variables to create a 
            default vector if zeros (value defined in implementation file)*/
            Vector();

            /* Allows for Vector command to parse Dimension numeber of type T 
            input variables to create the vector of desired length.
            Const prevents the function from altering the values during the execution*/
            explicit Vector(const T values[Dimension]);
            
            /*Allow Vector command to parse an already defined Vector of the same size
            in order to create a copy, without altering the original.*/
            Vector(const Vector<T, Dimension>& other);



};


}
#endif