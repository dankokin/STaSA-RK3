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

/*
double maxValue(const std::vector<std::pair<double, double>>& population) {
    std::vector<double> result;
    result.reserve(population.size());
    for (auto& i : population) {
        result.push_back(MathFunction(i.first, i.second));
    }
    return *std::max_element(result.begin(), result.end());
}

double averageValue(const std::vector<std::pair<double, double>>& population) {
    std::vector<double> result;
    result.reserve(population.size());
    for (auto& i : population) {
        result.push_back(MathFunction(i.first, i.second));
    }
    double sum = 0;
    for (auto& i : result) {
        sum += i;
    }
    return sum / result.size();
}

void print(std::vector<std::pair<double, double>> population, size_t i) {
    std::cout << std::setw(4) << i << std::setw(11) << std::fixed << std::setprecision(6) << population[0].first << std::setw(11) << population[0].second << std::setw(11) << MathFunction(population[0].first, population[0].second) << std::setw(13) << MaxValue(population) << std::setw(13) << averageValue(population) << std::endl;
    for (size_t j = 1; j < population.size(); ++j) {
        std::cout << std::setw(15) << std::fixed << std::setprecision(6) << population[j].first << std::setw(11) << population[j].second << std::setw(11) << MathFunction(population[j].first, population[j].second) << std::endl;
    }
    std::cout << std::endl;
}

std::vector<size_t> Roulette(std::vector<std::pair<double, double>>& points) {
    double sum = 0;
    for (auto value : points) {
        sum += MathFunction(value.first, value.second);
    }

    std::vector<size_t> answer;

    for (auto value : points) {
        answer.push_back(MathFunction(value.first, value.second) / sum * 100);
    }
    return answer;
}

size_t CheckIndex(std::vector<size_t>& prob, double p) {
    size_t a = 0;
    for (size_t i = 0; i < prob.size(); i++) {
        a += prob[i];
        if (a > p) return i;
        //if (p > prob[i]) return i;
    }
    return -1;
}

bool func_sort(std::pair<double, double> pair1, std::pair<double, double> pair2) {
    return (MathFunction(pair1.first, pair1.second) > MathFunction(pair2.first, pair2.second));
}

std::vector<std::pair<double, double>> Crossover(std::vector<size_t> prob,
                                                 std::vector<std::pair<double, double>>& points) {

    std::vector<std::pair<double, double>> answer;
    for (auto value : points) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> probability(0, 100);
        auto p = static_cast<double>(100 - probability(gen));

        size_t index = CheckIndex(prob, p);
        if (index != -1) {
            answer.push_back(std::make_pair(points[index].first, value.second));
            answer.push_back(std::make_pair(value.first, points[index].second));
        }
        //answer.push_back(std::make_pair(value.first, points[index].second));
        //answer.push_back(std::make_pair(value.second, points[index].first));

    }


    std::sort(answer.begin(), answer.end(), func_sort);
    //std::sort(answer.begin(), answer.end(),
    //[](std::pair<double, double> pair1, std::pair<double, double> pair2) {
    //return MathFunction(pair1.first, pair1.first) < MathFunction(pair2.first, pair2.second);
    //});

    answer.resize(4);
    return answer;
}

void Mutation(std::vector<std::pair<double, double>>& points) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> probability(0, 100);
    auto p = static_cast<size_t>(probability(gen));

    for (auto value : points) {
        if (p > 25) {
            std::uniform_real_distribution<double> probability(0, 100);
            auto p = static_cast<size_t>(probability(gen));
            if (p > 50) {
                value.first += 0.5;
                value.second += 0.5;
            }
            else {
                value.first -= 0.5;
                value.second -= 0.5;
            }
        }
    }
}

void genetic(int x1, int x2, int y1, int y2) {
    std::pair<double, double> individual;
    std::vector<std::pair<double, double>> population;
    // Генерация начальной популяции (4 рандомных особи)
    for (size_t i = 0; i < 4; ++i) {
        individual = generateIndividual(x1, x2, y1, y2);
        population.push_back(individual);
    }
    std::cout << std::setw(4) << "N" << std::setw(11) << "X" << std::setw(11) << "Y" << std::setw(11) << " FIT " << std::setw(13) << "MAX  " << std::setw(13) << "Average" << std::endl;

    for (size_t i = 0; i < 1000; ++i) {
        print(population, i);
        population = Crossover(Roulette(population), population);
        Mutation(population);
    }
}

*/