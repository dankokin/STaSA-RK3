#include "header.hpp"

Point lower(-2, -2);
Point upper(2, 2);

int main() {
    std::vector<Point> currentPopulation;
    currentPopulation.resize(4);
    printf("| %s |     %s    |     %s    |     %s    |     %s    |     %s    |", "№", "X", "Y", "FIT", "Максимальное", "Среднее");
    std::cout << std::endl;
    CreatePopulation(currentPopulation, lower, upper);
    print(currentPopulation, 0);
    for (size_t i = 1; i <= 10; ++i) {
        currentPopulation = Selection(currentPopulation);
        currentPopulation = Crossover(currentPopulation);
        Mutation(currentPopulation);
        print(currentPopulation, i);
    }
    return 0;
}