#pragma once

#include "SortingAlgorithm.h"

#include <SDL2/SDL_render.h>

#include <random>
#include <vector>

class QuickSort : public SortingAlgorithm {
public:
  QuickSort(SDL_Renderer *renderer, int width, int height);

  virtual void __sort(std::vector<int> &data) override;

private:
  void qsort(std::vector<int> &data, int low, int high);
  int partition(std::vector<int> &data, int low, int high);

  std::mt19937 gen;
};
