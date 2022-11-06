#include <iostream>
#include <stl_reader/stl_reader.h>

int main()
{
    try
    {
        stl_reader::StlMesh<float, unsigned int> mesh("./samples/conrod.stl");

        for (size_t itri = 0; itri < mesh.num_tris(); ++itri)
        {
            std::cout << "coordinates of triangle " << itri << ": ";
            for (size_t icorner = 0; icorner < 3; ++icorner)
            {
                // float *c = mesh.vrt_coords(mesh.tri_corner_ind(itri, icorner));
                // float *c = mesh.tri_corner_coords(itri, icorner);
                const float* c = mesh.vrt_coords (mesh.tri_corner_ind (itri, icorner));
                // or alternatively:
                // float* c = mesh.vrt_coords (mesh.tri_corner_ind (itri, icorner));
                std::cout << "(" << c[0] << ", " << c[1] << ", " << c[2] << ") ";
            }
            std::cout << std::endl;

            const float *n = mesh.tri_normal(itri);
            std::cout << "normal of triangle " << itri << ": "
                      << "(" << n[0] << ", " << n[1] << ", " << n[2] << ")\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}