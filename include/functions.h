#ifndef RRORELCALC_FUNCTIONS_H
#define RRORELCALC_FUNCTIONS_H

#include <vector>
#include <zconf.h>
#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>

double mathExpectation(const std::vector<ulong> &inputData, unsigned long gapPosition);

double mathExpectation(const std::vector<ulong> &inputData);

double squaredDispersionCalc(const std::vector<ulong> &inputData, unsigned long gapPosition);

double squaredDispersionCalc(const std::vector<ulong> &inputData);

double studentsDistribution(const std::vector<ulong> &inputData, unsigned long gapPosition);

void getRidOfRoughErrors(std::vector<ulong> &inputData);

bool checkEqualityOfDistributionCenters(const std::vector<ulong> &inputData,
                                        const std::vector<ulong> &perfectData);

bool differenceByAccidentalReasons(const std::vector<ulong> &inputData,
                                   const std::vector<ulong> &perfectData);

bool fullCheck(const std::vector<ulong> &perfectData, const std::vector<ulong> &inputData);

#endif //RRORELCALC_FUNCTIONS_H
