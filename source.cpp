#include "header.hpp"

double MathFunction(double x, double y) {
    return cos(x) * cos(y) * exp(-(x * x + y * y));
}

double RandomPoint(double lower, double upper) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(lower, upper);
    return dis(gen);
}

Point::Point(double x1, double x2, double y1, double y2) {
    x_ = RandomPoint(x1, x2);
    y_ = RandomPoint(y1, y2);
    fitValue_ = 0;
}

Point::Point(double x1, double y1) : x_(x1), y_(y1), fitValue_(MathFunction(x_, y_)) {}

void CreatePopulation(std::vector<Point>& population, Point& lower, Point& upper) {
    for (auto& value: population) {
        value.x_ = RandomPoint(lower.x_, upper.x_);
        value.y_ = RandomPoint(lower.y_, upper.y_);
        value.fitValue_ = MathFunction(value.x_, value.y_);
    }
}

std::vector<Point>Selection(const std::vector<Point>& currentPopulation) {
    // Подсчет суммы фит-функций
    double fitSum = 0;
    for (size_t i = 0; i < currentPopulation.size(); ++i) {
        fitSum += currentPopulation[i].fitValue_;
    }

    // Подсчет вероятности скрещивания с каждой особью
    std::vector<double>roulette(currentPopulation.size());
    for (size_t i = 0; i < roulette.size(); ++i) {
        roulette[i] = fabs(currentPopulation[i].fitValue_ / fitSum);
    }

    // Создание "рулеточного колеса"
    for (size_t k = 1; k < roulette.size(); ++k) {
        roulette[k] += roulette[k - 1];
    }

    // Генерируем вероятность и выбираем особь в зависимости от результата
    std::vector<Point> result;
    for (size_t j = 0; j < roulette.size(); ++j) {
        double p = RandomPoint(0.0, 1.0);
        for (size_t l = 0; l < roulette.size(); ++l) {
            if (p < roulette[l]) {
                result.push_back(currentPopulation[l]);
                break;
            }
        }
    }
    return result;
}

bool ComparePoints(Point& a, Point& b) {
    return a.fitValue_ > b.fitValue_;
}

std::vector<Point> Crossover(const std::vector<Point>& currentPopulation) {
    std::vector<Point> result;
    for (size_t i = 0; i < currentPopulation.size() - 1; ++i) {
        Point first(currentPopulation[i].x_, currentPopulation[i + 1].y_);
        Point second(currentPopulation[i + 1].x_, currentPopulation[i].y_);
        result.push_back(first);
        result.push_back(second);
    }
    std::sort(result.begin(), result.end(), ComparePoints);
    result.erase(result.begin() + 4, result.end());
    return result;
}

void Mutation(std::vector<Point>& currentPopulation) {
    for (auto& value : currentPopulation) {
        if (RandomPoint(0.0, 1.0) > 0.25) {
            if (RandomPoint(0.0, 1.0) > 0.5) {
                value.x_ -= 0.2;
                value.y_ -= 0.2;
                value.fitValue_ = MathFunction(value.x_, value.y_);
            } else {
                value.x_ += 0.2;
                value.y_ += 0.2;
                value.fitValue_ = MathFunction(value.x_, value.y_);
            }
        }
    }
}

double MaxValue(const std::vector<Point> &population) {
    double max = MathFunction(population[0].x_, population[0].y_);
    for (size_t i = 1; i < population.size(); ++i) {
        double tmp = MathFunction(population[i].x_, population[i].y_);
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}

double AverageValue(const std::vector<Point>& population) {
    double result = 0;
    for (const auto& value : population) {
        result += value.fitValue_;
    }
    return result / population.size();
}

void print(const std::vector<Point> &population, size_t i) {
    for (size_t j = 0; j < population.size(); ++j) {
        printf("|%3zu|%10f|%10f|%10f|%10f|%3f|", i, population[j].x_, population[j].y_, MathFunction(population[j].x_, population[j].y_),
               MaxValue(population), AverageValue(population));
        std::cout << std::endl;
    }
}
