#pragma once

#include "SortingAlgorithm.h"

#include <SDL2/SDL.h>

#include <vector>

class BubbleSort : public SortingAlgorithm {
public:
  BubbleSort(SDL_Renderer *renderer, int width, int height);

  virtual void __sort(std::vector<int> &data) override;
};
