// --- Constraint Value ---
final int GRAY_SCALE = 255;
final int TRANSPARENT = 0;
final color groupMemberColor = color(248,157,34);
final color groupLeaderColor = color(118,88,152);
final color gatewayColor = color(84,208,83);
final Position nodePosition = new Position(250,250);
final Size nodeSize = new Size(50,50);
final int backgroundWidth = 1000;
final int backgroundHeight = 500;
// --- Define Object ---
// GroupMember member = new GroupMember(nodePosition, nodeSize, groupMemberColor);
GroupLeader[] leaders = new GroupLeader[1];
GroupMember[] members = new GroupMember[4];
GatewayNode gateway;
int groupStatus;
final int statusOnActivate = 1;
final int statusOnDecidedGroup = 3;
void setup() {
    // init nodes
    int bgWidthCenter = int(backgroundWidth/2);
    int bgWidthHalf = bgWidthCenter/2;
    int bgHeightCenter = int(backgroundHeight/2);
    int bgHeightBottom = int(backgroundHeight/2) + 100;
    gateway = new GatewayNode(new Position(bgWidthCenter, bgHeightCenter-50), nodeSize, gatewayColor);
    background(GRAY_SCALE,TRANSPARENT);
    size(1000,500);
    // init leaders
    for(int i=1;i<=leaders.length;i++) {
        int x = bgWidthHalf * 2;
        int y = bgHeightBottom;
        leaders[i-1] = new GroupLeader(new Position(x,y), nodeSize, groupLeaderColor);
    }
    // init members on top
    int[] memberWidths = {int(bgWidthHalf*1.5+50),int(bgWidthHalf*2.5-50)};
    for(int i=1;i<=(members.length/2);i++) {
        int x = memberWidths[i-1];
        int y  = bgHeightBottom -50;
        members[i-1] = new GroupMember(new Position(x,y), nodeSize, groupLeaderColor);
    }
    // init member on bottom
    for(int i=(members.length/2)+1;i<=members.length;i++) {
        int x = memberWidths[i-(members.length/2)-1];
        int y  = bgHeightBottom + 50;
        members[i-1] = new GroupMember(new Position(x,y), nodeSize, groupLeaderColor);
    }
    groupStatus = statusOnActivate;
}

int i = 0;
void draw() {
    // refresh display
    background(GRAY_SCALE,TRANSPARENT);
    gateway.display();
    switch(groupStatus) {
      case statusOnActivate:
        for(GroupLeader leader: leaders) {
          leader.display();
          leader.displayParse(int(i/60)); 
        }
        for(GroupMember member: members) {
          member.display();
          member.displayParse(int(i/60)); 
        }
      case statusOnDecidedGroup:
        for(GroupLeader leader: leaders) {
          leader.display();
        }
        for(GroupMember member: members) {
          member.display();
        }
    }
    if (i==300) i = 0;
    i += 1;
    //saveFrame("frames/####.png");
    if (frameCount == 600) {
      groupStatus = statusOnDecidedGroup;
      for(GroupLeader leader: leaders) {
          leader.updateColor(groupLeaderColor);
      }
      for(GroupMember member: members) {
          member.updateColor(groupMemberColor);
      }
    }
}
