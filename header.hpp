#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <iostream>
#include <random>
#include <iomanip>

double MathFunction(double, double);

struct Point {
    double x_;
    double y_;
    double fitValue_;
    Point(double x1, double x2, double y1, double y2);
    Point() = default;
    Point(double x1, double y1);
};


double RandomPoint(double, double);

void CreatePopulation(std::vector<Point>&, Point&, Point&);

std::vector<Point>Selection(const std::vector<Point>&);

std::vector<Point> Crossover(const std::vector<Point>&);

bool ComparePoints(Point&, Point&);

void Mutation(std::vector<Point>&);

double MaxValue(const std::vector<Point> &population);

double AverageValue(const std::vector<Point>& population);

void print(const std::vector<Point>& population, size_t i);
