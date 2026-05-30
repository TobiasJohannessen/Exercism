namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

    enum class AccountStatus{
        troll,
        guest,
        user,
        mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

    enum class Action{
    read,
    write,
    remove,
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

    bool display_post(AccountStatus poster_status, AccountStatus viewer_status){
        switch (poster_status){
        case AccountStatus::troll:
            if (viewer_status == AccountStatus::troll){
                return true;
            }
            else{
                return false;
            };
            break;
        case AccountStatus::guest:
        case AccountStatus::user:
        case AccountStatus::mod:
            return true;
            break;
        }
        return true;
    }

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

    bool permission_check(Action action, AccountStatus account_status){
        switch (account_status){
            case AccountStatus::mod:
                return true;
                break;
            case AccountStatus::user:
                [[fallthrough]];
            case AccountStatus::troll:
                if (action == Action::write) return true;
                [[fallthrough]];
            case AccountStatus::guest:
                if (action == Action::read) return true;
                break;
        }
        return false;
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

    bool valid_player_combination(AccountStatus player_1, AccountStatus player_2){

        

        if ((player_1 == AccountStatus::guest)|| (player_2 == AccountStatus::guest)) return false;

        if (((player_1 == AccountStatus::troll) && (player_2 != AccountStatus::troll)) || 
            ((player_1 != AccountStatus::troll) && (player_2 == AccountStatus::troll))) 
            return false;

        
        return true;
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus account_1, AccountStatus account_2){

        // Convert accounts to unscoped enumerates
        int account_1_int = static_cast<int>(account_1);
        int account_2_int = static_cast<int>(account_2);

        //Account types are ordered according to priority, so we can just check whichever number is highest
        if (account_1_int > account_2_int) return true;
        
        
        return false;
    }
}  // namespace hellmath
