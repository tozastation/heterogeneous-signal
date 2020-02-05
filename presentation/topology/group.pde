// Group Node
class GatewayNode extends BaseNode {
    GatewayNode(Position _pos, Size _size, color _color) {
        super(_pos, _size, _color);
    }
}
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
    void display() {
        fill(this.baseColor);
        noStroke();
        ellipse(this.pos.getX(),this.pos.getY(),this.size.getWidth(),this.size.getHeight()); 
    }
    void displayParse(int parseNum) {
        for(int i=0;i<parseNum;i++) {
            fill(128,0);
            stroke(0);
            ellipse(this.pos.getX(),this.pos.getY(),this.size.getWidth()+(20*i),this.size.getHeight()+(20*i));
        }
    }
    void updatePosition(Position _pos) { this.pos = _pos; }
    void updateColor(color _color) { this.baseColor = _color; }
}
