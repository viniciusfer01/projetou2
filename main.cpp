#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip> 

using namespace std;

struct Voxel {
  float r,g,b; // Colors
  float a; // Transparency
  bool isOn; // Included or not
};

class Sculptor {
protected:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(char* filename);
};

int main() {
    Sculptor Voxel(5,5,5);
    Voxel.setColor(1,0,0,1);
    Voxel.putVoxel(1,1,1);

    // *char cu = 'c';
    // char* cuu = &cu;
    Voxel.writeOFF(cuu);

    return 0;
}

void Sculptor::cutVoxel(int x, int y, int z){
  v[x0][y0][z0].isOn = false;
}

void Sculptor::putVoxel(int x, int y, int z){
  v[x0][y0][z0].isOn = true;
  v[x0][y0][z0].r = r;
  v[x0][y0][z0].g = g;
  v[x0][y0][z0].b = b;
  v[x0][y0][z0].a = a;

}

/*
void Sculptor::writeOFF(char* filename){
  int total, index;
  ofstream f;
  total = 0;
  f.open(filename);
  f << "OFF\n";

  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          total++;
        }
      }
      
    }
    
  }

  f << total * 8 << " " << total * 6 << "0 \n";

  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          f << x - lado << " " << y + lado << " " << z - lado << "\n" << flush;
          f << x - lado << " " << y - lado << " " << z - lado << "\n" << flush;
          f << x + lado << " " << y - lado << " " << z - lado << "\n" << flush;
          f << x + lado << " " << y + lado << " " << z - lado << "\n" << flush;
          f << x - lado << " " << y + lado << " " << z + lado << "\n" << flush;
          f << x - lado << " " << y - lado << " " << z + lado << "\n" << flush;
          f << x + lado << " " << y - lado << " " << z + lado << "\n" << flush;
          f << x + lado << " " << y + lado << " " << z + lado << "\n" << flush;
  
        }
      }
    }
      
  }

  total = 0;  
  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          index = total * 8;

          f << std::fixed;
          f << 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " index + 1 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          f << 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " index + 7 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";
        }
      }
      
    }
    
  }
}
*/

  