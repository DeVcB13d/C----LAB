/* Write a C++ program to define classes Shapes, Circle, Square, Ellipse and
Rectangle with member functions to get the values for finding corresponding
areas and print the same. Utilize the concept of Abstract Class and Runtime
polymorphism to solve the problem.*/

class shape
{
    protected:
        float area;
    public:
        virtual float area();
};

class circle : public shape
{
    int r;
    public:
        float area(float r)
        {
            
        }
};
