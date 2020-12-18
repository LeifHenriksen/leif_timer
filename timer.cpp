#include <iostream>
#include <chrono>
#include <string>
#include <unistd.h>

std::string seconds_to_hhmmss(int s)
{
  int h = s / 3600;
  s = s - (h * 3600);
  int m = s / 60;
  s = s - (m * 60);

  return (h > 9? std::string( 6 - std::to_string(h).length(), ' ') + std::to_string(h) : "    0" + std::to_string(h)) + " : " +
         (m > 9? std::to_string(m) : "0" + std::to_string(m)) + " : " +
         (s > 9? std::to_string(s) : "0" + std::to_string(s));
}

int main()
{
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  for(;;)
  {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\r=========== Timer ============\n";
    std::cout << "\r||                          ||\n";
    std::cout << "\r||   " << seconds_to_hhmmss(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()) << "       ||\n";
    std::cout << "\r||                          ||\n";
    std::cout << "\r==============================\n" << std::flush;
    std::cout << "\x1b[A";
    std::cout << "\x1b[A";
    std::cout << "\x1b[A";
    std::cout << "\x1b[A";
    std::cout << "\x1b[A";
    usleep(100000);
  }

  return 0;
}
