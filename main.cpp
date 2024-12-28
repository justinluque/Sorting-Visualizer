#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <SDL2/SDL_video.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "BubbleSort.h"
#include "QuickSort.h"

enum class AlgorithmChoice { QUICKSORT, BUBBLESORT };

// change chosen algorithm here
constexpr AlgorithmChoice choice = AlgorithmChoice::QUICKSORT;

constexpr int width = 100;
constexpr int height = 100;
constexpr int scale = 5;

void render(SDL_Renderer *renderer, AlgorithmChoice choice,
            std::vector<int> &data, int width, int height) {
  switch (choice) {
  case AlgorithmChoice::BUBBLESORT: {
    BubbleSort algorithm(renderer, width, height);
    algorithm.sort(data);
    break;
  }
  case AlgorithmChoice::QUICKSORT: {
    QuickSort algorithm(renderer, width, height);
    algorithm.sort(data);
    break;
  }
  default: {
    std::cerr << "Invalid algorithm choice. ";
    break;
  }
  }
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL failed to initialize.\n";
    return 1;
  }

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_CreateWindowAndRenderer(width * scale, height * scale, 0, &window,
                              &renderer);
  SDL_RenderSetScale(renderer, scale, scale);
  SDL_SetWindowTitle(window, "Sorting Visualizer");
  SDL_RaiseWindow(window);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<int> data(width);

  for (size_t i = 0; i < data.size(); i++) {
    data[i] = (i + 1) * height / width;
  }

  std::shuffle(data.begin(), data.end(), gen);

  std::thread renderThread(render, renderer, choice, std::ref(data), width,
                           height);

  bool running = true;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = false;
    }
  }

  if (renderThread.joinable())
    renderThread.join();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  for (const int &num : data)
    std::cout << num << ' ';

  return 0;
}
