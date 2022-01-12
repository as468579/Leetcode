class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        // North = (0, -1), East = (1, 0), South = (0, 1), West = (-1, 0)
        int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        int pos_x = 0, pos_y = 0, dir_ind = 0;
        int direction[2] = {directions[dir_ind][0], directions[dir_ind][1]};
        for(char &c: instructions){
            if(c == 'G'){
                pos_x += direction[0];
                pos_y += direction[1];
            }
            else if(c == 'L'){
                dir_ind = ((dir_ind - 1) >= 0) ? (dir_ind - 1) : (dir_ind + 3);
                direction[0] = directions[dir_ind][0];
                direction[1] = directions[dir_ind][1];
            }
            else if(c == 'R'){
                dir_ind = ((dir_ind + 1) < 4) ? (dir_ind + 1) : (dir_ind - 3);
                direction[0] = directions[dir_ind][0];
                direction[1] = directions[dir_ind][1];              
            }
        }
        
        // If the robot comes back to origin or the final vector doesn't face North(origin)
        // Note: (move == 0) || ((move != 0) && (dir_ind != 0)) is equal to 
        //       (move == 0) || (dir_ind != 0)  
        if(((pos_x == 0) && (pos_y == 0)) || (dir_ind != 0)){
            return true;    
        }
        return false;
        
    }
};