class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> pos; //store all boundary cell positions
//O(WIDTH + HEIGHT)
//SC O(WIDTH*2 + HEIGHT*2)
    Robot(int width, int height) {
        //bottom row(left to right) -> east(0)
        for(int x=0;x<width; x++){
            pos.push_back({x,0,0});
        }
        
        //right col (bottom to top) -> North(1)
        for(int y=1;y<height; y++){
            pos.push_back({width-1,y,1});
        }

        //top row (right to left) -> WEST(2)
        for(int x=width - 2;x>=0; x--){
            pos.push_back({x,height-1,2});
        }

        //left column (top to column) -> south(3)
        for(int y=height -2; y>0; y--){
            pos.push_back({0,y,3});
        }

        pos[0][2] = 3; //corner case 

    }
    
    void step(int num) {
        moved = true;
        idx = (idx+num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {
        if(!moved) return "East";

        int d = pos[idx][2];
        if(d==0) return "East";
        else if(d==1) return "North";
        else if(d==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */