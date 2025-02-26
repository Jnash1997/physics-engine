#ifndef VECTOR_H
#define VECTOR_H

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
            // Constructors

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
                for(int i = 0; i < Dimenstion; i++){
                    components[i] = values[i];
                };
            };
            
            /*Allow Vector command to create a new vector by copying all values 
            from an existing vector of the same type and dimension, without 
            altering the original.*/
            Vector(const Vector<T, Dimension>& other){
                for(int i = 0; i < Dimension; i++){
                    /* Still requires operator[] definition to access components 
                    of a given index; this implementation will not work yet!!! */
                    components[i] = other[i];
                }
            };



};


}
#endif