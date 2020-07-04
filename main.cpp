/**
* rewrite of physical operation program in c++, as practice and massive speedup for the system.
* christopher Rehm christopherrehm@web.de
*
* started 27 june 2020
*
* uses c++ 17 spec.  developed on codeblocks 20.03 IDE
* this program is a faster version of the python physical control system,
* it is being developed to practice c++17 coding
*
*
*/
#include <fstream>
#include <iostream>
#include <vector>

#include <experimental/filesystem>

#include "main.h"
#include "proccessingFunctions.h"

namespace fs = std::experimental::filesystem;

struct std_message {
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

    std::string unprocessed_messages_path = "/home/christopher/test/";
    std::string processed_messages_path = "/home/christopher/toherefolder/";
    bool run_this_program = true;
    std::string operator_choice;
    std::vector<std::string> new_msg_list;
    std::string current_msg_path;
    std::string msg_file_name;
    std::string line;
    long int loop_counter = 0;

    std::cout << "Starting physical management program now\n";
    while(run_this_program == true){
        std::cout << "This is the top of the processing loop" << std::endl;
        if (!fs::is_empty(unprocessed_messages_path)){
            for (const auto & entry : fs::directory_iterator(unprocessed_messages_path)){
                std_message current_msg;
                current_msg_path = entry.path();
                std::cout << entry.path() << std::endl;
                std::cout << entry << std::endl;
                std::cout << fs::path(entry).filename() << '\n';
                msg_file_name = fs::path(entry).filename();
                std::cout << current_msg_path << std::endl;
                std::cout << std::endl;
                new_msg_list.push_back(current_msg_path);
                std::ifstream current_working_file (current_msg_path);
                current_msg.msg_title = msg_file_name;
                std::getline (current_working_file, current_msg.msg_time);
                std::getline (current_working_file, current_msg.msg_sender);
                std::getline (current_working_file, current_msg.msg_title2);
                std::getline (current_working_file, current_msg.msg_text);
                std::getline (current_working_file, current_msg.msg_priority);
                std::getline (current_working_file, current_msg.msg_receiver);
                std::getline (current_working_file, current_msg.msg_otherreceivers);
                std::getline (current_working_file, current_msg.msg_files);
                std::cout << current_msg.msg_time << std::endl;
                std::cout << current_msg.msg_sender << std::endl;
                std::cout << current_msg.msg_title2 << std::endl;
                std::cout << current_msg.msg_text << std::endl;
                std::cout << current_msg.msg_priority << std::endl;
                std::cout << current_msg.msg_receiver << std::endl;
                std::cout << current_msg.msg_otherreceivers << std::endl;
                std::cout << current_msg.msg_files << std::endl;
                //msg is in struct now you can use it

                 //ok do something with each message
                if(current_msg.msg_title2== "activateCam1"){
                    std::cout << "in  activate cam 1 function" << std::endl;
                    turn_on_r_camera();
                }else if (current_msg.msg_title2 == "activateCam2" ){
                    std::cout << "in  activate cam 2 function" << std::endl;
                    turn_on_l_camera();
                }else if (current_msg.msg_title2 == "activateHearing"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "deactivateHearing"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "moveHead"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "sendInternetInquiry"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "processFoto" ){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "processVideo"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "processAudio"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "receiveInternet"){
                    std::cout << "in   function" << std::endl;
                }else if (current_msg.msg_title2 == "shutdownMe"){
                    std::cout << "in   function" << std::endl;
                }else {
                    std::cout << "cannot process message" << std::endl;
                }
                // once done move the message to the done folder.
                fs::rename(unprocessed_messages_path + msg_file_name, processed_messages_path + msg_file_name);
            }
        }
        // do other tasks
        //this is some loop stopping code only here for testing.
        if ((loop_counter % 10000) == 0 ){
            std::cout << "The loop counter value is" << loop_counter << std::endl;
            std::cin >> operator_choice;
            if(operator_choice == "quit" || operator_choice == "q"){
               run_this_program =false;
            }
        }
        loop_counter++;
    }
    std::cout << "program finished. see you later.\n";
    return 0;
}

