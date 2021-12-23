#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream infile(argv[1]);

        std::vector < std::pair < double, double >> partition;
        double h;
        double x = 0;

        infile >> h;

        double vx, vy;
        infile >> vx >> vy;

        double g = -9.81;

        int interval = 0;
        int size = 0;

        while (true) {
            int target = (vx > 0) ? interval : interval - 1;
            if (target < 0) {
                std::cout << "0" << std::endl;
                return 0;
            }
            if (target > size - 1) {
                double x_obs, h_obs;
                if (infile >> x_obs >> h_obs) {
                    partition.push_back(std::make_pair(x_obs, h_obs));
                    size++;
                } else {
                    std::cout << size << std::endl;
                    return 0;
                }

            }

            double t = std::abs((x - partition[target].first) / vx);

            x = partition[target].first;
            h = h + vy * t + 0.5 * g * t * t;
            vy = vy + g * t;

            if (h <= 0) {
                std::cout << interval << std::endl;
                return 0;
            }
            if (h > partition[target].second) {
                (vx > 0) ? interval++ : interval--;
            } else {
                vx = vx * (-1);
            }
        }
    }
}
