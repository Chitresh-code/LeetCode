class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dis = 0;
        set<pair<int, int>> obstacleSet;
        for (auto &obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        //initially facing north

        map< pair<int,int> , pair<pair<int,int> , pair<int,int>> >dir;
        //coord -> left,right

        dir[{0,1}] = {{-1,0},{1,0}};
        dir[{-1,0}] = {{0,-1},{0,1}};
        dir[{0,-1}] = {{1,0},{-1,0}};
        dir[{1,0}] = {{0,1},{0,-1}};

        pair<int,int>face = {0,1};
        pair<int,int>pos = {0,0};

        for(auto command : commands){

            if(command < 0){
                if(command == -1){
                    //turn right
                    face = dir[face].second;
                }
                else{
                    //turn left
                    face = dir[face].first;
                }
            }
            else{
                // now we have to move in the direction of our face
                int delx = face.first;
                int dely = face.second;

                int flag = 0; //flag = 1 means that we ran into an obstacle

                while(command){
                    pair<int,int>nextpos = {pos.first + delx , pos.second +dely};
                    if (obstacleSet.find(nextpos) != obstacleSet.end()){
                        //we ran into obstacle
                        flag = 1;
                        break;
                    }
                    else{
                        pos = {nextpos.first , nextpos.second};
                        int currDis = (pos.first * pos.first) + (pos.second * pos.second);
                        dis = max(dis , currDis);
                        command--;
                    }
                }

                if(flag == 1){
                    continue;
                    //continue to the next command
                }
            }

        }

        return dis;
    }
};