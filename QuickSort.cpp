#include "QuickSort.h"

#include <SDL2/SDL.h>

#include <random>
#include <utility>
#include <vector>

#include "Color3.h"

QuickSort::QuickSort(SDL_Renderer *renderer, int width, int height)
    : SortingAlgorithm(renderer, width, height), gen(std::random_device{}()) {}

void QuickSort::__sort(std::vector<int> &data) {
  qsort(data, 0, data.size() - 1);
}

void QuickSort::qsort(std::vector<int> &data, int low, int high) {
  if (low < high) {
    int p = partition(data, low, high);
    qsort(data, low, p - 1);
    qsort(data, p + 1, high);
  }
}

int QuickSort::partition(std::vector<int> &data, int low, int high) {
  std::uniform_int_distribution<> dist(low, high);
  int pivot = dist(gen);
  int pivotVal = data[pivot];

  std::swap(data[pivot], data[high]);
  int i = low - 1;

  for (int j = low; j < high; j++) {
    std::vector<std::pair<size_t, Color3>> coloredLines{
        std::make_pair(i, Color3(255, 0, 0)),  // R
        std::make_pair(j, Color3(0, 0, 255))}; // B
    visualize(data, coloredLines);
    if (data[j] < pivotVal) {
      i++;
      std::swap(data[i], data[j]);
    }
  }

  std::swap(data[i + 1], data[high]);

  std::vector<std::pair<size_t, Color3>> emptyList(0);
  visualize(data, emptyList);

  return i + 1;
}
