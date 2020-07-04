/**
*rewrite of physical operation program in c++, as practice and massive speedup for the system.
*christopher Rehm christopherrehm@web.de
*started 27 june 2020
*/
#include <fstream>
#include <iostream>
#include <vector>

#include <experimental/filesystem>

#include "main.h"
#include "proccessingFunctions.h"

namespace fs = std::experimental::filesystem;

struct mymessage {
    std::string msg_title = "__";
    std::string msg_time = "__";
    std::string msg_sender = "__";
    std::string msg_title2 = "__";
    std::string msg_text = "__";
    std::string msg_priority = "__";
    std::string msg_receiver = "__";
    std::string msg_otherreceivers = "__";
    std::string msg_files = "__";
};

int main(){
    /** \brief
     *
     * \param
     * \param
     * \return
     *
     */

    std::string path = "/home/christopher/test/";
    std::string processed_path = "/home/christopher/toherefolder/";
    bool run_this_program = true;
    std::string my_choice;
    std::vector<std::string> new_msg_list;
    std::string my_storage_string;
    std::string current_msg;
    std::string line;
    long int loop_counter = 0;

    std::cout << "Starting physical management program now\n";
    while(run_this_program == true){
        std::cout << "This is the top of the processing loop" << std::endl;
        if (!fs::is_empty(path)){
            for (const auto & entry : fs::directory_iterator(path)){
                mymessage the_msg;
                my_storage_string = entry.path();
                std::cout << entry.path() << std::endl;
                std::cout << entry << std::endl;
                std::cout << fs::path(entry).filename() << '\n';
                current_msg = fs::path(entry).filename();
                std::cout << my_storage_string << std::endl;
                std::cout << std::endl;
                new_msg_list.push_back(my_storage_string);
                std::ifstream myfile (my_storage_string);
                the_msg.msg_title = current_msg;
                std::getline (myfile, the_msg.msg_time);
                std::getline (myfile, the_msg.msg_sender);
                std::getline (myfile, the_msg.msg_title2);
                std::getline (myfile, the_msg.msg_text);
                std::getline (myfile, the_msg.msg_priority);
                std::getline (myfile, the_msg.msg_receiver);
                std::getline (myfile, the_msg.msg_otherreceivers);
                std::getline (myfile, the_msg.msg_files);
                std::cout << the_msg.msg_time << std::endl;
                std::cout << the_msg.msg_sender << std::endl;
                std::cout << the_msg.msg_title2 << std::endl;
                std::cout << the_msg.msg_text << std::endl;
                std::cout << the_msg.msg_priority << std::endl;
                std::cout << the_msg.msg_receiver << std::endl;
                std::cout << the_msg.msg_otherreceivers << std::endl;
                std::cout << the_msg.msg_files << std::endl;
                //msg is in struct now you can use it

                 //ok do something with each message
                if(the_msg.msg_title2== "activateCam1"){
                    turn_on_r_camera();
                }else if (the_msg.msg_title2 == "activateCam2" ){
                    turn_on_l_camera();
                }else if (the_msg.msg_title2 == "activateHearing"){
                }else if (the_msg.msg_title2 == "deactivateHearing"){
                }else if (the_msg.msg_title2 == "moveHead"){
                }else if (the_msg.msg_title2 == "sendInternetInquiry"){
                }else if (the_msg.msg_title2 == "processFoto" ){
                }else if (the_msg.msg_title2 == "processVideo"){
                }else if (the_msg.msg_title2 == "processAudio"){
                }else if (the_msg.msg_title2 == "receiveInternet"){
                }else if (the_msg.msg_title2 == "shutdownMe"){
                }else {
                    std::cout << "cannot process message" << std::endl;
                }
                // once done move the message to the done folder.
                fs::rename(path + current_msg, processed_path + current_msg);
            }
        }
        // do other tasks
        //this is some loop stopping code only here for testing.
        if ((loop_counter % 100000) == 0 ){
            std::cout << "The loop counter value is" << loop_counter << std::endl;
            std::cin >> my_choice;
            if(my_choice == "quit" || my_choice == "q"){
               run_this_program =false;
            }
        }
        loop_counter++;
    }
    std::cout << "program finished. see you later.\n";
    return 0;
}

