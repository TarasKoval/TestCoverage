#include "functions.h"

double mathExpectation(const std::vector<ulong> &inputData, unsigned long gapPosition) {
    double mathematicalExpectation = 0;
    double temp = 0;
    auto size = inputData.size();

    for (unsigned long i = 0; i < size; i++) {
        if (i == gapPosition) {
            continue;
        }
        temp += inputData.at(i);
    }

    mathematicalExpectation = temp / (size - 1);
    return mathematicalExpectation;
}

double mathExpectation(const std::vector<ulong> &inputData) {
    double mathematicalExpectation = 0;
    double temp = 0;
    auto size = inputData.size();

    for (unsigned long i = 0; i < size; i++) {
        temp += inputData.at(i);
    }

    mathematicalExpectation = temp / size;
    return mathematicalExpectation;
}

double squaredDispersionCalc(const std::vector<ulong> &inputData, unsigned long gapPosition) {
    double squaredDispersion = 0;
    double temp = 0;
    auto size = inputData.size();

    for (unsigned long i = 0; i < size; i++) {
        if (i == gapPosition) {
            continue;
        }
        temp += std::pow((inputData.at(i) - mathExpectation(inputData, i)), 2);
    }
    squaredDispersion = temp / (size - 2);
    return squaredDispersion;
}

double squaredDispersionCalc(const std::vector<ulong> &inputData) {
    double squaredDispersion = 0;
    double temp = 0;
    auto size = inputData.size();

    for (unsigned long i = 0; i < size; i++) {
        temp += std::pow((inputData.at(i) - mathExpectation(inputData, i)), 2);
    }
    squaredDispersion = temp / (size - 1);
    return squaredDispersion;
}

double studentsDistribution(const std::vector<ulong> &inputData, unsigned long gapPosition) {
    double distribution = 0;
    double squaredDispersion = squaredDispersionCalc(inputData, gapPosition);
    double dispersion = std::pow(squaredDispersion, 0.5);
    double temp = inputData.at(gapPosition) - mathExpectation(inputData, gapPosition);

    distribution = temp / dispersion;
    return distribution;
}

void getRidOfRoughErrors(std::vector<ulong> &inputData) {
    double tempDistribution = 0;
    std::array<double, 10> perfectStudDistribution = {6.314, 2.920, 2.353, 2.132, 2.015,
                                                      1.943, 1.895, 1.860, 1.833, 1.812};

    for (unsigned long i = 0; i < inputData.size(); i++) {
        tempDistribution = studentsDistribution(inputData, i);
        if (tempDistribution > perfectStudDistribution.at(i)) {
            inputData.erase(inputData.begin() + i);
        }
    }
}

bool checkEqualityOfDistributionCenters(const std::vector<ulong> &inputData,
                                        const std::vector<ulong> &perfectData) {

    std::array<std::array<double, 10>, 10> perfectFisherDistribution = {
            std::array<double, 10>{161.45, 18.51, 10.13, 7.71, 6.61, 5.99, 5.59, 5.32, 5.12, 4.97},
            std::array<double, 10>{199.50, 19.00, 9.55, 6.94, 5.79, 5.14, 4.74, 4.46, 4.26, 4.10},
            std::array<double, 10>{215.71, 19.16, 9.28, 6.59, 5.41, 4.76, 4.35, 4.07, 3.86, 3.71},
            std::array<double, 10>{224.58, 19.25, 9.12, 6.39, 5.19, 4.53, 4.12, 3.84, 3.63, 3.48},
            std::array<double, 10>{230.16, 19.30, 9.01, 6.26, 5.05, 4.39, 3.97, 3.69, 3.48, 3.33},
            std::array<double, 10>{233.99, 19.33, 8.94, 6.16, 4.95, 4.28, 3.87, 3.58, 3.37, 3.22},
            std::array<double, 10>{236.77, 19.35, 8.89, 6.09, 4.88, 4.21, 3.79, 3.50, 3.29, 3.14},
            std::array<double, 10>{238.88, 19.37, 8.85, 6.04, 4.82, 4.15, 3.73, 3.44, 3.23, 3.07},
            std::array<double, 10>{240.54, 19.39, 8.81, 6.00, 4.77, 4.10, 3.68, 3.39, 3.18, 3.02},
            std::array<double, 10>{241.88, 19.40, 8.79, 5.96, 4.74, 4.06, 3.64, 3.35, 3.14, 2.98}
    };
    auto squaredDispersionOfInputData = squaredDispersionCalc(inputData, 1);
    auto squaredDispersionOfPerfectData = squaredDispersionCalc(perfectData, 1);

    auto minDispersion = std::min(squaredDispersionOfInputData, squaredDispersionOfPerfectData);
    auto maxDispersion = std::max(squaredDispersionOfInputData, squaredDispersionOfPerfectData);

    auto distributionOfFisher = maxDispersion / minDispersion;
    auto perfectDistribution = perfectFisherDistribution.at(inputData.size() - 1).at(inputData.size() - 1);

    return (distributionOfFisher < perfectDistribution);
}

bool differenceByAccidentalReasons(const std::vector<ulong> &inputData,
                                   const std::vector<ulong> &perfectData) {

    std::array<double, 10> perfectStudDistribution = {6.314, 2.920, 2.353, 2.132, 2.015,
                                                      1.943, 1.895, 1.860, 1.833, 1.812};

    auto mathExpectationOfInputData = mathExpectation(inputData);
    auto mathExpectationOfPerfectData = mathExpectation(perfectData);

    auto squaredDispersionOfInputData = squaredDispersionCalc(inputData);
    auto squaredDispersionOfPerfectData = squaredDispersionCalc(perfectData);

    auto temp = std::pow(squaredDispersionOfPerfectData, 2);
    auto numerator = std::pow(squaredDispersionOfInputData, 2) + temp * (inputData.size() - 1);
    auto denominator = 2 * inputData.size() - 1;
    auto mainDispersion = pow((numerator / denominator), 0.5);

    auto studDistributionNumerator = std::abs(mathExpectationOfInputData - mathExpectationOfPerfectData);
    auto studDistributionDenominator = mainDispersion * std::pow(((double) 2 / inputData.size()), 0.5);
    auto studDistribution = studDistributionNumerator / studDistributionDenominator;

    return (studDistribution < perfectStudDistribution.at(inputData.size() - 1));
}

bool fullCheck(const std::vector<ulong> &perfectData, const std::vector<ulong> &inputData) {
    auto localPerfectData = perfectData;
    auto localInputData = inputData;

    getRidOfRoughErrors(localPerfectData);
    getRidOfRoughErrors(localInputData);

    if (checkEqualityOfDistributionCenters(localPerfectData, localInputData)) {
        return differenceByAccidentalReasons(localPerfectData, localInputData);
    } else {
        return false;
    }
}
