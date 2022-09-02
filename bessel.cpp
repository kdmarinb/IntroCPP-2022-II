
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>

// function declaration
void bessel(const std::string & filename);

int main(int argc, char **argv)
{
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);
    const std::string file = "data.txt";
    bessel(file);

    return 0;

}


void bessel(const std::string & filename)
{
  double Jo = 0.0;
  double Ji = 0.0;
  double x = 0.0;

  std::ofstream fout;
  fout.open(filename);
  fout.setf(std::ios::scientific);
  fout.precision(15);

  int xmin = 0;
  int xmax = 10;
  double deltax = 0.05;
  int nsteps = ((xmax-xmin)/deltax);


  for(int step = 0; step <= nsteps ; step++)
  {
      double x = xmin + step*deltax;
      Jo = std::cyl_bessel_j(0,x);
      Ji = std::cyl_bessel_j(1,x);

      fout << x << "\t" << Jo << "\t" << Ji << "\n";
  }
  fout.close();
}
