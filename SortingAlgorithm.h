#pragma once

#include <SDL2/SDL.h>

#include <vector>

#include "Color3.h"

class SortingAlgorithm {
protected:
  virtual void __sort(std::vector<int> &data) = 0;

  SDL_Renderer *renderer;
  int width;
  int height;

public:
  SortingAlgorithm(SDL_Renderer *renderer, int width, int height);

  virtual ~SortingAlgorithm() = default;

  virtual void sort(std::vector<int> &data);

  virtual void
  visualize(std::vector<int> &data,
            const std::vector<std::pair<size_t, Color3>> &coloredLines) const;
};
