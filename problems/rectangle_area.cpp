// Find the total area covered by two rectilinear rectangles in a 2D plane.
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
// Assume that the total area is never beyond the maximum possible value of int.

#include <algorithm>

using namespace std;

int ComputeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int dx = 0;
    if (A <= E) {
        if (E < C)
            dx = min(C, G) - E;
    } else {
        if (A < G)
            dx = min(C, G) - A;
    }
    int dy = 0;
    if (B <= F) {
        if (F < D)
            dy = min(D, H) - F;
    } else {
        if (B < H)
            dy = min(D, H) - B;
    }
    return (C - A) * ( D - B) + (G - E) * (H - F) - dx * dy;
}
