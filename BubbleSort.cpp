#include "BubbleSort.h"

#include <SDL2/SDL.h>

#include <utility>
#include <vector>

#include "Color3.h"

BubbleSort::BubbleSort(SDL_Renderer *renderer, int width, int height)
    : SortingAlgorithm(renderer, width, height) {}

void BubbleSort::__sort(std::vector<int> &data) {
  bool swapped = true;

  size_t size = data.size() - 1;
  while (swapped) {
    swapped = false;

    for (size_t i = 0; i < size; i++) {
      std::vector<std::pair<size_t, Color3>> coloredLines = {
          std::make_pair(i, Color3(255, 0, 0)),
          std::make_pair(i + 1, Color3(0, 0, 255))};
      visualize(data, coloredLines);
      if (data[i] > data[i + 1]) {
        std::swap(data[i], data[i + 1]);
        swapped = true;
      }
    }
    size--;
  }
}
