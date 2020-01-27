final int GRAY_SCALE = 255;
final int TRANSPARENT = 0;
final color groupMember = color(255,221,221);
final color groupLeader = color(221,238,255);

GroupMember member = new GroupMember(new Position(250,250),new Size(50,50), groupMember);


void setup() {
    background(GRAY_SCALE,TRANSPARENT);
    size(500,500);
    member.draw();
}

int i = 0;
void draw() {
    // refresh display
    background(GRAY_SCALE,TRANSPARENT);
    i += 1;
    member.updatePosition(new Position(i,i));
    member.draw();
}

// Group Node
class GroupLeader extends BaseNode {
    GroupLeader(Position _pos, Size _size, color _color) {
        super(_pos, _size, _color);
    }
}
class GroupMember extends BaseNode {
    GroupMember(Position _pos, Size _size, color _color) {
        super(_pos, _size, _color);
    }
}
// Base Node
class BaseNode {
    Position pos;
    Size size;
    color baseColor;
    BaseNode(Position _pos, Size _size, color _color) {
        pos = _pos;
        size = _size;
        baseColor = _color;
    }
    void draw() {
        fill(this.baseColor);
        noStroke();
        ellipse(this.pos.getX(),this.pos.getY(),this.size.getWidth(),this.size.getHeight()); 
    }
    void updatePosition(Position _pos) { this.pos = _pos; }
}
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