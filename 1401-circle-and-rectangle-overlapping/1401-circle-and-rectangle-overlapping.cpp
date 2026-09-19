class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xclosest = 0;
        if(x1>xCenter){
            xclosest = x1;
        }
        else if(x2<xCenter){
            xclosest = x2;
        }
        else{
            xclosest = xCenter;
        }
        int yclosest = 0;
        if(y1>yCenter){
            yclosest = y1;
        }
        else if(y2<yCenter){
            yclosest = y2;
        }
        else{
            yclosest = yCenter;
        }
        int dx = xCenter-xclosest;
        int dy = yCenter-yclosest;
        return dx*dx + dy*dy <= radius*radius;

    }
};