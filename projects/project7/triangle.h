#include <iostream>
#include <fstream>

using namespace std;

class triangle
{
        public:
                triangle(int = 0, int = 0);
                triangle(const triangle&);
                ~triangle();
                triangle& operator=(const triangle&);
                bool operator==(const triangle&) const;

                friend triangle operator+(const triangle&, const triangle&);
                friend ostream& operator<<(ostream&, triangle&);
                friend ifstream& operator>>(ifstream&, triangle&);

        private:
                int base;
                int height;
                double area;
};