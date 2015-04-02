#include "triangle.h"

triangle::triangle(int a, int b){
	base = a;
	height = b;
	area = (base*height)/2;
}

triangle::triangle(const triangle &t){
	base = t.base;
	height = t.height;
	area = (base*height)/2;
}

triangle::~triangle(){
	base = 0;
	height = 0;
	area = 0;
}

triangle& triangle::operator=(const triangle &t){
	//make sure the operator does not self-corrupt the data
	if(this != &t){
		base = t.base;
		height = t.height;
		area = t.area;
	}
	return *this;
}

bool triangle::operator==(const triangle &t) const{
	bool stat;
	//check each value for equality
	if(base == t.base)
		stat = true;
	else
		stat = false;
	if(height == t.height)
		stat = true;
	else
		stat = false;
	if(area == t.area)
		stat = true;
	else
		stat = false;
	return stat;
}

triangle operator+(const triangle &o, const triangle &t){
	triangle result; //create a triangle to hold the result
	
	//add the two triangles elements together
	result.base = o.base+t.base;  
	result.height = o.height + t.height;
	//compute the new area
	result.area = (result.base*result.height)/2;
	return result;

}

ostream& operator<<(ostream &output, triangle &t){
	//output all the elements of the triangle
	output << t.base << " " << t.height << " " << t.area;
	return output;
}

ifstream& operator>>(ifstream &input, triangle &t){
	//scan in the base and height
	input >> t.base >> t.height;
	//calculate the area
	t.area = (t.base*t.height)/2;
	return input;
}
