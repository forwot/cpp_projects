#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main(){
    bool run = true;
    const int MAX_INVENTORY {25}; 
    std::string names[MAX_INVENTORY];
    int ids[MAX_INVENTORY];
    int item_count {};
    

    while(run){
        std::cout << std::endl;
        std::cout << "-----Welcome to the Inventory Management System-----" << std::endl;
        
        std::cout << "1. Search Item by ID" << std::endl;
        std::cout << "2. Add Item" << std::endl;
        std::cout << "3. List all Items" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Select (use no.): ";

        int select;
        std::cin >> select;
        std::cout << std::endl;

        //for non-integer inputs in selection
        if (std::cin.fail()) {
            std::cout << "\nERROR: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        //menu cases
        switch(select){
            case 1:{     //search item by ID
                std::cout << std::endl;
                if(item_count == 0){
                    std::cout << "Inventory is empty!" << std::endl;
                }
                
                else{
                    std::cout << "ID to search: ";
                    int id{};
                    std::cin >> id;
                    std::cout << "Commencing Search..." << std::endl;
                    bool item_found {false};
                    for(int q{}; q < item_count; q++){
                        if(ids[q] == id){
                            item_found = true;
                            std::cout << "Name: " << names[q] << std::endl;
                        }
                    }

                    if(!item_found){
                        std::cout << "Item not found!" << std::endl;
                    }
                }
                break;
            }

            case 2:{     //adding items
            std::string name{};
            int id{};
                if(item_count >= MAX_INVENTORY){
                    std::cout << "Unable to add. Inventory full." << std::endl;
                    break;
                }

                std::cout << "Item Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Item ID Number: ";
                std::cin >> id;
            
                //Check if got duplicate id
                while(true){
                    bool id_duplicate {false};
                    for(int i{}; i < item_count; i++){
                        if(id == ids[i]){
                            id_duplicate = true;
                            break;
                        } 
                    }
                    if(id_duplicate == true){
                        std::cout << "ID already in use, new ID: ";
                        std::cin >> id;
                    }
                    else{
                        break;
                    }
                }

                names[item_count] = name;
                ids[item_count] = id;
                item_count++;

                std::cout << std::endl;
                std::cout << "Item Successfully Added!" << std::endl;
                break;
            }
            case 3:     //list all items
                if(item_count == 0){
                    std::cout << "Nothing in inventory!" << std::endl;
                }
                else{
                    std::cout << "Listing all items..." << std::endl;
                    for (int i{}; i < item_count; i++){
                        std::cout << "Name: " << std::setw(8) << names[i] << "   ID: " << ids[i] << std::endl;
                    }
                }
                std::cout << std::endl;
                break;
            
            case 4:     //exit program
                run = false;
                break;

            default:    
                std::cout << "Invalid selection. Please choose an option from (1-4)." << std::endl;
                std::cout << std::endl;
                break;

        }
    }       
    std::cout << "Thanks for using The Inventory!" << std::endl;
    return 0;
}