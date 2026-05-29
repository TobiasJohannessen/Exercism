namespace targets {
class Alien {
    public:
        Alien(int x, int y){
            x_coordinate = x;
            y_coordinate = y;
            health = 3;
        };

        int get_health(){
            return health;
        };

        bool hit(){
            health -= 1;
            return true;
        }

        bool is_alive(){
            if (health <= 0){
                health = 0;
                return false;
            }
            return true;
        }

        bool teleport(int x_new, int y_new){
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        bool collision_detection(Alien other){

            if ((x_coordinate == other.x_coordinate) && (y_coordinate == other.y_coordinate)){
                return true;
            }
            return false;
        }
        //Position
        int x_coordinate;
        int y_coordinate;

    private:
        int health;
    };

}  // namespace targets
