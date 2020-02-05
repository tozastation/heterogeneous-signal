// Value Object
class Size {
    int width;
    int height;
    Size(int _width, int _height) {
        width = _width;
        height = _height;
    }
    int getWidth() { return this.width; }
    int getHeight() { return this.height; }
}
class Position {
    int x;
    int y;
    Position(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int getX() { return this.x; }
    int getY() { return this.y; }
}