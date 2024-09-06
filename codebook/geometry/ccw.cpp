int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}