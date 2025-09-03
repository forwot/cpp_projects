#include <iostream>

int main(){
    bool run_prog {true};
    unsigned short int user_permissions {};
    unsigned short int read_bit {1};
    unsigned short int write_bit = static_cast<short int>(read_bit << 1);
    unsigned short int exe_bit = static_cast<short int>(read_bit << 2);
    unsigned short int dlt_bit = static_cast<short int>(read_bit << 3);
    
    while(run_prog){

        std::cout << "----- Permissions Menu -----" << std::endl;
        std::cout << "1. Grant Permission " << std::endl;
        std::cout << "2. Revoke Permission " << std::endl;
        std::cout << "3. Check Permission " << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Select an Option > ";

        unsigned short int select {};
        std::cin >> select;
        std::cout << std::endl;

        //handler for non-int inputs
        if (std::cin.fail()) {
            std::cout << "\nERROR: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        switch(select){
            case 1:{        //GRANTING PERMISSION
                std::cout << "Which permission do you wish to GRANT?" << std::endl;
                std::cout << "(R)ead, (W)rite, (E)xecute, (D)elete: > ";
                unsigned char select_perm {};
                std::cin >> select_perm;
                std::cout << std::endl;

                if(select_perm == 'R' || select_perm == 'r'){
                    user_permissions = static_cast<short int>(read_bit | user_permissions);
                    std::cout << "Permission 'READ' granted." << std::endl;
                }
                
                else if(select_perm == 'W' || select_perm == 'w'){
                    user_permissions = static_cast<short int>(write_bit | user_permissions);
                    std::cout << "Permission 'WRITE' granted." << std::endl;
                }

                else if(select_perm == 'E' || select_perm == 'e'){
                    user_permissions = static_cast<short int>(exe_bit | user_permissions);
                    std::cout << "Permission 'EXECUTE' granted." << std::endl;
                }

                else if(select_perm == 'D' || select_perm == 'd'){
                    user_permissions = static_cast<short int>(dlt_bit | user_permissions);
                    std::cout << "Permission 'DELETE' granted." << std::endl;
                }
                else{
                    std::cout << "Please a valid character!";
                }
                std::cout << std::endl;
                break;
            }
            
            case 2:{        //REVOKE PERMISSION
                std::cout << "Which permission do you wish to REVOKE?" << std::endl;
                std::cout << "(R)ead, (W)rite, (E)xecute, (D)elete: > ";
                unsigned char select_perm {};
                std::cin >> select_perm;
                std::cout << std::endl;

                if(select_perm == 'R' || select_perm == 'r'){
                    user_permissions = static_cast<short int>(~read_bit & user_permissions);
                    std::cout << "Permission 'READ' revoked.";
                }
                
                else if(select_perm == 'W' || select_perm == 'w'){
                    user_permissions = static_cast<short int>(~write_bit & user_permissions);
                    std::cout << "Permission 'WRITE' revoked."; 
                }

                else if(select_perm == 'E' || select_perm == 'e'){
                    user_permissions = static_cast<short int>(~exe_bit & user_permissions);
                    std::cout << "Permission 'EXECUTE' revoked.";
                }

                else if(select_perm == 'D' || select_perm == 'd'){
                    user_permissions = static_cast<short int>(~dlt_bit & user_permissions);
                    std::cout << "Permission 'DELETE' revoked.";
                }
                else{
                    std::cout << "Please a valid character!";
                }
                std::cout << std::endl << std::endl;
                break;
            }

            case 3:{        //CHECKING PERMISSIONS
                std::cout << "CURRENT PERMISSIONS:";
                bool first {true};
                
                if(user_permissions == 0){
                    std::cout << " [NONE]";
                }
                if(user_permissions & read_bit){
                    if(!first){
                        std::cout << ",";
                    }
                    first = false;
                    std::cout << " READ";
                }
                if(user_permissions & write_bit){
                    if(!first){
                        std::cout << ",";
                    }
                    first = false;
                    std::cout << " WRITE";
                }
                if(user_permissions & exe_bit){
                    if(!first){
                        std::cout << ",";
                    }
                    first = false;
                    std::cout << " EXECUTE";
                }
                if(user_permissions & dlt_bit){
                    if(!first){
                        std::cout << ",";
                    }
                    first = false;
                    std::cout << " DELETE"; 
                }
                std::cout << std::endl << std::endl;  
                break;
            }

            case 4:
                run_prog = false;
                break;

            default: 
                std::cout << "Please select with a valid number (1-4): " << std::endl;
        }
    }
    std::cout << "Thank you for using the Permissions Manager!" << std::endl;
    std::cout << std::endl;
}