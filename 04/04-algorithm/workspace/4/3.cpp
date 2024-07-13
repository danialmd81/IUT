#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>> conditions;
int gridSize, numConditions;
int validCombinations = 0;
bool grid[40];
int minConditionIndex = -1;

bool checkGrid() {
    for (int i = 0; i < conditions.size(); i++) {
        if (i != minConditionIndex) {
            int sameCount = 0;
            for (int j = 0; j < gridSize; j++) {
                sameCount += ((conditions[i].second[j] - '0') == grid[j]);
            }
            if (sameCount != conditions[i].first)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> gridSize >> numConditions;

    int conditionIdx = 0;
    while (conditionIdx < numConditions) {
        string pattern;
        int matchCount;
        cin >> pattern >> matchCount;
        conditions.push_back({ matchCount, pattern });
        if (minConditionIndex == -1 || conditions[minConditionIndex].first > matchCount)
            minConditionIndex = conditionIdx;
        conditionIdx++;
    }

    int i = 0;
    while (i < gridSize) {
        grid[i] = !(conditions[minConditionIndex].second[i] - '0');
        i++;
    }

    if (conditions[minConditionIndex].first == 0) {
        cout << checkGrid() << endl;
        return 0;
    }

    int minMatchCount = conditions[minConditionIndex].first;

    i = 0;
    while (i < gridSize - minMatchCount + 1) {
        grid[i] = (conditions[minConditionIndex].second[i] - '0');
        if (conditions[minConditionIndex].first == 1) {
            validCombinations += checkGrid();
        } else {
            int j = i + 1;
            while (j < gridSize - minMatchCount + 2) {
                grid[j] = (conditions[minConditionIndex].second[j] - '0');
                if (conditions[minConditionIndex].first == 2) {
                    validCombinations += checkGrid();
                } else {
                    int k = j + 1;
                    while (k < gridSize - minMatchCount + 3) {
                        grid[k] = (conditions[minConditionIndex].second[k] - '0');
                        if (conditions[minConditionIndex].first == 3) {
                            validCombinations += checkGrid();
                        } else {
                            int x = k + 1;
                            while (x < gridSize - minMatchCount + 4) {
                                grid[x] = (conditions[minConditionIndex].second[x] - '0');
                                if (conditions[minConditionIndex].first == 4) {
                                    validCombinations += checkGrid();
                                } else {
                                    int z = x + 1;
                                    while (z < gridSize - minMatchCount + 5) {
                                        grid[z] = (conditions[minConditionIndex].second[z] - '0');
                                        if (conditions[minConditionIndex].first == 5) {
                                            validCombinations += checkGrid();
                                            continue;
                                        }
                                        grid[z] = !(conditions[minConditionIndex].second[z] - '0');
                                        z++;
                                    }
                                }
                                grid[x] = !(conditions[minConditionIndex].second[x] - '0');
                                x++;
                            }
                        }
                        grid[k] = !(conditions[minConditionIndex].second[k] - '0');
                        k++;
                    }
                }
                grid[j] = !(conditions[minConditionIndex].second[j] - '0');
                j++;
            }
        }
        grid[i] = !(conditions[minConditionIndex].second[i] - '0');
        i++;
    }

    cout << validCombinations;
    return 0;
}
