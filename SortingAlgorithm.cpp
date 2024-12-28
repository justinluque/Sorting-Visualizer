#include "SortingAlgorithm.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <algorithm>
#include <utility>
#include <vector>

#include "Color3.h"

SortingAlgorithm::SortingAlgorithm(SDL_Renderer *renderer, int width,
                                   int height)
    : renderer(renderer), width(width), height(height) {}

void SortingAlgorithm::sort(std::vector<int> &data) {
  __sort(data);

  for (size_t i = 0; i < data.size() - 1; i++) {
    std::vector<std::pair<size_t, Color3>> coloredLines = {
        std::make_pair(i, Color3(0, 255, 0)),
        std::make_pair(i + 1, Color3(0, 255, 0))};
    visualize(data, coloredLines);
  }
}

void SortingAlgorithm::visualize(
    std::vector<int> &data,
    const std::vector<std::pair<size_t, Color3>> &coloredLines) const {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  for (size_t i = 0; i < data.size(); i++) {
    auto search = std::find_if(
        coloredLines.begin(), coloredLines.end(),
        [i](const std::pair<long long unsigned int, Color3> &element) {
          return element.first == i;
        }

    );
    if (search != coloredLines.end()) {
      auto rgb = search->second;
      SDL_SetRenderDrawColor(renderer, rgb.r, rgb.g, rgb.b, 255);
    } else
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawLine(renderer, i, height - 1, i, height - data[i]);
  }

  SDL_RenderPresent(renderer);

  SDL_Delay(10);
}
