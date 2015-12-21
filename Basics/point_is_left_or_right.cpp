// A  program in C++ to find if a point is to the right or left of a line
#include <iostream>
#include <cstdio>
using namespace std;

// structure to represent a Point in 2D plane
struct point{
	double x;
	double y;
};

// A structure to represent a Straight-line in 2D plane
struct sLine{
	double x;
	double y;
	double m;
	double b;
};


double f(sLine *sl){
	return sl->m*sl->x + sl->b;
}

// constant 'a' and 'b' different to zero
double condPoint(sLine *sl, point *b){
	point pa;
	point *a;
	a = &pa;
	a->x = sl->x = 1;
	a->y = f(sl);

	point pc;
	point *c;
	c = &pc;
	c->x = sl->x = -1;
	c->y = f(sl);

	double cond = ((a->x - b->x)*(c->y - b->y)) - ((c->x - b->x)*(a->y - b->y));
	cout<<cond<<endl;
	return cond;
}

int main(){

	//Create a rect
	sLine l0;
	sLine *l;
	l = &l0;

	//read straight line
	cin>>l->m;
	cin>>l->b;

	//create a point
	point p0;
	point *p;
	p = &p0;

	//read point
	cin>>p->x;
	cin>>p->y;

	double cond = condPoint(l,p);

	if(cond ==0) printf("%s\n", "the point p belongs to the line" );
	else if(cond > 0) printf("%s\n", "point p is on the right" );
		else printf("%s\n", "point p is on the left" );

	return 0;
}